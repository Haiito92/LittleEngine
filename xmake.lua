
------------------ Tasks ------------------

includes("tasks/**.lua")

------------------ Rules ------------------

add_rules("mode.debug", "mode.release")
add_requires("fmt")

set_languages("c++20")
set_encodings("utf-8")

add_includedirs("inc")

--------------- Extra Files ---------------

target("ExtraFiles")
    set_kind("phony")
    add_extrafiles("README.md", ".gitignore")
    add_extrafiles("tasks/**.lua", "xmake.lua")

--------------- Engine ---------------

local static = true

engineModules = {
    Core = {
        }
    }

for name, module in pairs(engineModules) do
    
    target(name)
        set_kind(static and "static" or "shared")
            
        if static then
            add_defines("LE_STATIC")
        end
    
        set_group("Engine")
        
        add_defines("LE_" .. name:upper() .. "_COMPILE")
        
        add_headerfiles("inc/(Little/Engine/" .. name .. "/**.hpp)")
        add_headerfiles("inc/(Little/Engine/" .. name .. "/**.inl)")
        add_files("src/Little/Engine/" .. name .. "/**.cpp")
end
    
--------------- Launcher ---------------    
    
target("Launcher")
    set_kind("binary")    
    set_group("Launcher")
    
    if static then
        add_defines("LE_STATIC")
    end
    
    for name, module in pairs(engineModules) do
        add_deps(name)        
    end
    
    add_files("src/Little/Launcher/**.cpp")
