add_rules("mode.debug", "mode.release")

set_languages("c++20")
set_encodings("utf-8")

--------------- Engine ---------------

target("Engine")
    set_kind("static")
    set_group("Engine")
    add_files("src/Little/Engine/**.cpp")
    
--------------- Launcher ---------------    
    
target("Launcher")
    set_kind("binary")    
    set_group("Launcher")
    
    add_deps("Engine")
    
    add_files("src/Little/Launcher/**.cpp")
