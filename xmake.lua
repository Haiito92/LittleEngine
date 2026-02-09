
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
    add_extrafiles("tasks/**.lua")

--------------- Engine ---------------

engineModules = {
    Core = {
        },
    Renderer = {
        }
    }

for name, module in pairs(engineModules) do
    
    target(name)
        set_kind("static")
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
    
    for name, module in pairs(engineModules) do
        add_deps(name)        
        end
    
    add_files("src/Little/Launcher/**.cpp")
