task("create_class")
    set_menu {
        usage = "xmake create_class [options]",
        description = "Create the header and source file for a class, in the current directory.",
        options = {
                {"n", "name", "kv", nil, "Class name (required)"},
                {"p", "path", "kv", nil, "Path relative to root directory (required)"},
                {"m", "module", "kv", nil, "Module (required)"},
                {"s", "namespace", "kv", nil, "Namespace (optional)"},
                {"i", "inline", "kv", nil, "With inline (optional)"}
            }
        }
    
    on_run(function()
        import("core.base.option")
        
        --- Get options ---
        local class_name = option.get("name")
        local relative_path_string = option.get("path")
        local module_name = option.get("module")
        local namespace = option.get("namespace")
        local with_inline = option.get("inline")
        
        if not class_name or class_name == "" then
            print("Error: Class name is required!")
            print("Usage: xmake create_class -n ClassName -p RelativePath -m ModuleName")  
            return
        end
    
        if not relative_path_string or relative_path_string == "" then
            print("Error: Relative path is required!")
            print("Usage: xmake create_class -n ClassName -p RelativePath -m ModuleName")  
            return
        end
    
        if not module_name or module_name == "" then
            print("Error: Module name is required!")
            print("Usage: xmake create_class -n ClassName -p RelativePath -m ModuleName")  
            return
        end
        
        local cwd = os.curdir()
        
        --- Create header content ---
        local guard = "LE_" .. (module_name and module_name:upper() .. "_" or "") .. class_name:upper() .. "_HPP"
    
        local header_content = string.format([[
#pragma once

#ifndef %s
#define %s

#include %s

%s

    class %s 
    {
    public:
    
        %s
        %s
        %s
        %s
        
        %s
        %s
        
    private:
    };

%s

%s

#endif // %s
        ]],
        guard,
        guard,
        "<Little/Engine/" .. module_name .. "/Export.hpp>",
        (namespace ~= nil and namespace ~= "")  and "namespace " .. namespace .. " {"or "",
        "LE_" .. (module_name and module_name:upper() .. "_" or "") .. "API " .. class_name,
        class_name .. "();",
        class_name .. "(const " .. class_name .. "& other) = delete;",
        class_name .. "(" .. class_name .. "&& other) = delete;",
        "~" .. class_name .. "();",
        class_name .. "& operator=(const " .. class_name .. "& other) = delete;",
        class_name .. "& operator=(" .. class_name .. "&& other) = delete;",
        (namespace ~= nil and namespace ~= "") and "}" or "",
        with_inline and "#include \"" .. class_name .. ".inl\"" or "",
        guard
        )
    
        
    
         --- Create source content ---
         local source_content = string.format([[
#include %s

%s

    %s

    %s
    
%s
         
                 ]],
                 "<" .. relative_path_string .. "/".. class_name .. ".hpp>",
                 (namespace ~= nil and namespace ~= "")  and "namespace " .. namespace .. " {"or "",
                 class_name .. "::" .. class_name .. "() = default;",
                 class_name .. "::~" .. class_name .. "() = default;",
                 (namespace ~= nil and namespace ~= "") and "}" or ""
                 )
         
    
        --- Write files ---
        local header_path = path.join(cwd, "inc/" .. relative_path_string, class_name .. ".hpp")
        io.writefile(header_path, header_content)
        
        local source_path = path.join(cwd, "src/" .. relative_path_string, class_name .. ".cpp")
        io.writefile(source_path, source_content)
        
        
        if with_inline then
            --- Create inline content ---
            local inline_content = string.format([[
%s



%s
             ]],
             (namespace ~= nil and namespace ~= "")  and "namespace " .. namespace .. " {"or "",
             (namespace ~= nil and namespace ~= "") and "}" or ""
             )
         
            --- Write inline content ---
            local inline_path = path.join(cwd, "inc/" .. relative_path_string, class_name .. ".inl")
            io.writefile(inline_path, inline_content)                 
        end
    end
    )