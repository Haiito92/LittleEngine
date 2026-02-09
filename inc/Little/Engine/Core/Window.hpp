#pragma once

#ifndef LE_CORE_WINDOW_HPP
#define LE_CORE_WINDOW_HPP

#include <Little/Engine/Core/Export.hpp>

namespace LE {

    class LE_CORE_API Window 
    {
    public:
    
        Window();
        Window(const Window& other) = delete;
        Window(Window&& other) = delete;
        ~Window();
        
        Window& operator=(const Window& other) = delete;
        Window& operator=(Window&& other) = delete;
        
    private:
    };

}



#endif // LE_CORE_WINDOW_HPP
        