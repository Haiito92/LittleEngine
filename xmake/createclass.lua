task("create-class")
    
    set_menu {
        usage = "xmake create-class name [options]",
        description = "Creates files for a new class.",
        options = {
            {'n', "name", "kv", nil, "The name of the class to create."},
            {'m', "module", "kv", nil, "The module of the class."},
            {'p', "path", "kv", "", "The relative path of the files, under the module folder, or under the root folder if no module is specified."},
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
    
        -- options --
        local module = option.get("module")
        local optionalPath = path.unix(option.get("path"))
        local noInl = option.get("noinl")
        local noCpp = option.get("nocpp")
        
        local rootPath = module and path.join("LittleEngine", module, optionalPath) or path.join("LittleEngine", optionalPath)
    
        local function createFile(rootDir, relativePath, content)
            
            local filePath = path.join(rootDir, relativePath)
            
            io.writefile(filePath, content)    
        end

        -- file paths --
        local headerPath = path.unix(path.join(rootPath, name .. ".hpp"))
        local inlinePath = path.unix(path.join(rootPath, name .. ".inl"))
        local sourcePath = path.unix(path.join(rootPath, name .. ".cpp"))

        -- common strings --    
        local copyright = "// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)\n\n"
        local api = module and "LE_" .. module .. "_API " or "" 
        local export = module and "#include <LittleEngine/" .. module .. "/Export.hpp>\n\n" or ""
        local inlineInclude = not noInl and "#include <".. inlinePath ..">\n" or ""
        
        -- header --
        createFile("inc", headerPath, [[
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
    };
}

]]..inlineInclude..[[
]])
    
        -- inline --
        if not noInl then
            createFile("inc", inlinePath, [[
]]..copyright..[[
]])
        end
    
        -- source --
        if not noCpp then
            local headerInclude = "#include <".. headerPath ..">\n\n"
            
            createFile("src", sourcePath, [[
]]..copyright..[[
]]..headerInclude..[[
]])
        end
    
        print(name .. " class created!")
    end)
    