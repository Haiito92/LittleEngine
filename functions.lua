function add_common_defines(static)
    if static then
        add_defines("LE_STATIC")
    end

    if is_os("windows") then
        add_defines("LE_WINDOWS", "NOMINMAX", "WIN32_LEAN_AND_MEAN", "_CRT_SECURE_NO_WARNINGS")
    elseif is_os("linux") then
        add_defines("LE_LINUX")
    elseif is_os("macosx") then
        add_defines("LE_MACOS")
    end

end