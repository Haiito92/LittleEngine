----- tasks -----
includes("xmake/createclass.lua")
includes("xmake/createmodule.lua")

----- modules -----

add_rules("mode.debug", "mode.release")
set_languages("c++23")

add_requires("fmt", "libsdl3")

add_includedirs("inc")

modules = {
    Core = {
        Defines = {"LE_CORE_COMPILE"},
        Packages = {"libsdl3"},
        PublicPackages = {"fmt"}
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
        
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.hpp)")
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.inl)")
        add_files("src/LittleEngine/" .. name.. "/**.cpp")
end

target("LittleLauncher")
    set_kind("binary")
    add_files("src/main.cpp")
    
    for name, module in pairs(modules) do
        add_deps("LittleEngine" .. name)
    end
