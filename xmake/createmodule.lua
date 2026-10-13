task("create-module")
    
    set_menu {
        usage = "xmake create-module name [options]",
        description = "Creates files for a new module.",
        options = {
            {'n', "name", "kv", nil, "The name of the module to create."},
            {'f', "firstClassName", "kv", nil, "The name of the first class of the module."}
        }
    }
    
    on_run(function()
        import("core.base.option")
        import("core.project.config")
        import("core.base.task")
        
        local moduleName = option.get("name")
        
        if not moduleName then
            raise("You need to specify a module name.")
        end
        
        print("Creating module with name: " .. moduleName)
    
        local exportPath = path.join("inc", "LittleEngine", moduleName, "Export.hpp")
        local upperName = string.upper(moduleName)
        local copyright = "// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)\n\n"
        
        io.writefile(exportPath, [[
]]..copyright..[[
#pragma once

#ifdef LE_]]..upperName..[[_COMPILE
#define LE_]]..upperName..[[_API __declspec(dllexport)
#else
#define LE_]]..upperName..[[_API __declspec(dllimport)
#endif
]])
        local firstClassName = option.get("firstClassName")
        
        if firstClassName then
            task.run("create-class", {name = firstClassName, module = moduleName})
        end
    
        print(moduleName .. " module created!")
    end)
    