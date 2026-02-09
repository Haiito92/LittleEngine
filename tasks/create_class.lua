task("create_class")
    set_menu {
        usage = "xmake create_class [options]",
        description = "Create the header and source file for a class, in the current directory.",
        options = {
                {"-n", "Class name (required)"},
                {"-ns",  "Namespace (optional)"},
            }
        }