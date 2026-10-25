// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>

namespace Le
{
    struct Event;

    class LE_CORE_API IEventManager    
    {
    public:
        virtual ~IEventManager();
    
        virtual bool PollEvent(Event& event) const = 0;        
    };
}
