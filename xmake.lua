----- tasks -----
includes("xmake/createclass.lua")
includes("xmake/createmodule.lua")

----- modules -----

add_rules("mode.debug", "mode.release")
set_languages("c++23")

add_requires("libsdl3")
add_includedirs("inc")

modules = {
    Core = {
        Packages ={"libsdl3"}
        }
    }

for name, module in pairs(modules) do
    target("LittleEngine" .. name)
        set_group("LittleEngine")
        set_kind("shared")
        
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.hpp)")
        add_headerfiles("inc/(LittleEngine/" .. name .. "/**.inl)")
        add_files("src/LittleEngine/" .. name.. "/**.cpp")
    end

target("LittleLauncher")
    add_packages("libsdl3")
    set_kind("binary")
    add_files("src/main.cpp")
