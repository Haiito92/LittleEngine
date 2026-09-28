task("create-class")
    
    set_menu {
        usage = "xmake create-class name [options]",
        description = "Creates files for a new class.",
        options = {
            {'n', "name", "kv", nil, "The name of the class to create."},
            {'m', "module", "kv", nil, "The module of the class."},
            {nil, "noinl", "k", nil, "For classes with no inl file."},
            {nil, "nocpp", "k", nil, "For classes with no cpp file."}
        }
    }
    
    on_run(function()
        import("core.base.option")
        import("core.project.config")
        
        local name = option.get("name")
        if not name then
            raise("You need to specify a class name.")
        end
        
        print("Creating class with name: " .. name)
    
        local module = option.get("module")
        
        local rootPath = module and path.join("LittleEngine", module) or "LittleEngine"
    
        local function createFile(rootDir, ext, content)
            local filePath = path.join(rootDir, rootPath, name .. ext)
            -- if os.isfile(filePath) then return end
            
            io.writefile(filePath, content)    
        end
    
        local copyright = "// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)\n\n"
        local api = module and "LE_" .. module .. "_API " or "" 
        local export = module and "#include <LittleEngine/" .. module .. "/Export.hpp>\n\n" or ""
        local inline = "#include <LittleEngine" .. (module and "/" .. module or "") .. "/" .. name .. ".inl>\n" or ""
        local header = "#include <LittleEngine" .. (module and "/" .. module or "") .. "/" .. name .. ".hpp>\n\n"
        -- header --
        createFile("inc", ".hpp", [[
]]..copyright..[[
#pragma once

]].. export ..[[
namespace Le
{
    class ]]..string.upper(api)..[[]].. name ..[[
    
    {
    public:
        ]] .. name ..[[() = default;
        ]] .. name ..[[(const ]] .. name ..[[& other) = delete;
        ]] .. name ..[[(]] .. name ..[[&& other) = delete;
        ~]] .. name ..[[() = default;

        ]] .. name ..[[& operator=(const ]] .. name ..[[& other) = delete;
        ]] .. name ..[[& operator=(]] .. name ..[[&& other) = delete;
    private:
    }
}

]]..inline..[[
]])
    
        -- inline --
        if not option.get("noinl") then
            createFile("inc", ".inl", [[
]]..copyright..[[
]])
        end
    
        -- source --
        if not option.get("nocpp") then
            createFile("src", ".cpp", [[
]]..copyright..[[
]]..header..[[
]])
        end
    
        print(name .. " class created!")
    end)
    