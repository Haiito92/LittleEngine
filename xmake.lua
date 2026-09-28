----- tasks -----
includes("xmake/createclass.lua")

----- modules -----

add_rules("mode.debug", "mode.release")
set_languages("c++23")

add_requires("libsdl3")

-- modules = {
--     Core = {
--         Packages ={"libsdl3"}
--         }
--     }
-- 
-- for name, module in pairs(modules) do
--     target("LittleEngine" .. name)
--         set_group("LittleEngine")
--         set_kind("shared")
--     end

target("LittleLauncher")
    add_packages("libsdl3")
    set_kind("binary")
    add_files("src/*.cpp")
