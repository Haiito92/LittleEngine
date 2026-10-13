----- tasks -----
includes("xmake/createclass.lua")
includes("xmake/createmodule.lua")

----- modules -----

add_rules("mode.debug", "mode.release")
set_languages("c++23")
set_encodings("utf-8")

add_requires("fmt", "libsdl3")

add_includedirs("inc")

modules = {
    Platform = {
        Defines = {"LE_PLATFORM_COMPILE"},
        Packages = {"libsdl3"},
        PublicPackages = {"fmt"},
        },
    Core = {
        Defines = {"LE_CORE_COMPILE"},
        Packages = {"libsdl3"},
        PublicPackages = {"fmt"},
        Deps = {"LittleEnginePlatform"} 
        },
    Rendering = {
        Defines = {"LE_RENDERING_COMPILE"},
        Deps = {"LittleEnginePlatform", "LittleEngineCore"} 
        }
    }

for name, module in pairs(modules) do
    target("LittleEngine" .. name)
        set_group("LittleEngine")
        set_kind("shared")
        
        if module.Defines then
            add_defines(table.unpack(module.Defines))
        end
    
        if module.Packages then
            add_packages(table.unpack(module.Packages))
        end
    
        if module.PublicPackages then
            for _,pkg in ipairs(module.PublicPackages) do
                add_packages(pkg, {public = true})
            end
        end
    
        if module.Deps then
            add_deps(table.unpack(module.Deps))
        end
        
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.hpp)")
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.inl)")
        add_files("src/LittleEngine/" .. name.. "/**.cpp")
end

target("LittleLauncher")
    set_kind("binary")
    add_files("src/main.cpp")
    add_packages("libsdl3", "fmt")
    
    
    for name, module in pairs(modules) do
        add_deps("LittleEngine" .. name)
    end
