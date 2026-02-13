
------------------ Lua Includes ------------------

includes("tasks/**.lua")
includes("functions.lua")

------------------ Rules ------------------

add_rules("mode.debug", "mode.release")
add_requires("fmt")

set_languages("c++20")
set_encodings("utf-8")

add_includedirs("inc")

--------------- Extra Files ---------------

target("ExtraFiles")
    set_kind("phony")
    add_extrafiles("README.md", ".gitignore", "TODO.txt")
    add_extrafiles("tasks/**.lua", "xmake.lua", "functions.lua")


--------------- Engine ---------------

local static = true

engineModules = {
    Core = {
        SystemLinks = {"user32.lib"},
        PublicPkg = {"fmt"}
        },
    Renderer = {
        }
    }

for name, module in pairs(engineModules) do
    
    target(name, function()
        set_kind(static and "static" or "shared")
        set_group("Engine")
            
        add_common_defines(static)
        add_defines("LE_" .. name:upper() .. "_COMPILE")
    
        if module.SystemLinks then
            for _, sysLnk in ipairs(module.SystemLinks) do
                add_syslinks(sysLnk)
            end
        end
    
        if module.PublicPkg then
            for _, pkg in ipairs(module.PublicPkg) do
                add_packages(pkg, {public = true})
            end
        end
    
        add_headerfiles("inc/(Little/Engine/" .. name .. "/**.hpp)")
        add_headerfiles("inc/(Little/Engine/" .. name .. "/**.inl)")
        add_files("src/Little/Engine/" .. name .. "/**.cpp")
        
    end)
end
    
--------------- Launcher ---------------    
    
target("Launcher")
    set_kind("binary")    
    set_group("Launcher")
    
    add_common_defines(static)
    
    for name, module in pairs(engineModules) do
        add_deps(name)        
    end
    
    add_files("src/Little/Launcher/**.cpp")
