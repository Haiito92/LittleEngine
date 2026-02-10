#pragma once

#ifndef LE_CORE_CORE_HPP
#define LE_CORE_CORE_HPP

#include <Little/Engine/Core/Export.hpp>

namespace LE {

    class LE_CORE_API Core 
    {
    public:
    
        Core();
        Core(const Core& other) = delete;
        Core(Core&& other) = delete;
        ~Core();
        
        Core& operator=(const Core& other) = delete;
        Core& operator=(Core&& other) = delete;
        
    private:
    };

}



#endif // LE_CORE_CORE_HPP
        