// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <LittleEngine/Core/Export.hpp>
#include <cstdint>
#include <SDL3/SDL_events.h>

namespace Le
{
    enum class EventType : std::uint32_t;
    
    struct  LE_CORE_API Event    
    {
    public:
        Event() = default;
        Event(const Event& other) = delete;
        Event(Event&& other) noexcept = default;
        ~Event() = default;

        Event& operator=(const Event& other) = delete;
        Event& operator=(Event&& other) noexcept = default;
        
        
        
        EventType eventType;
        SDL_Event sdlEvent;
    };

    enum class LE_CORE_API EventType : std::uint32_t
    {
        First,
        Quit,
        Terminating,
        LowMemory,
        WillEnterBackground,
        DidEnterBackground,
        WillEnterForeground,
        DidEnterForeground,
        LocaleChanged,
        SystemThemeChanged,
        DisplayOrientation,
        DisplayAdded,
        DisplayRemoved,
        DisplayMoved,
        DisplayDesktopModeChanged,
        DisplayCurrentModeChanged,
        DisplayContentScaleChanged,
        DisplayFirst,
        DisplayLast,
        WindowShown,
        WindowHidden,
        WindowExposed,
        WindowMoved,             
        WindowResized,           
        WindowPixelSizeChanged,
        WindowMetalViewResized,
        WindowMinimized,         
        WindowMaximized,         
        WindowRestored,          
        WindowMouseEnter,       
        WindowMouseLeave,       
        WindowFocusGained,      
        WindowFocusLost,        
        WindowCloseRequested,   
        WindowHitTest,          
        WindowICCProfChanged,   
        WindowDisplayChanged,   
        WindowDisplayScaleChanged,
        WindowSafeAreaChanged,
        WindowOccluded,         
        WindowEnterFullscreen, 
        WindowLeaveFullscreen, 
        WindowDestroyed,        
        WindowHDRStateChanged,
        WindowFirst,
        WindowLast,
        KeyDown,
        KeyUp,                  
        TextEditing,            
        TextInput,              
        KeymapChanged,          
        KeyboardAdded,          
        KeyboardRemoved,        
        TextEditingCandidates, 
        MouseMotion,
        MouseButtonDown,       
        MouseButtonUp,         
        MouseWheel,   
        MouseAdded,   
        MouseRemoved, 
        JoystickAxisMotion,
        JoystickBallMotion,    
        JoystickHatMotion,     
        JoystickButtonDown,    
        JoystickButtonUp,      
        JoystickAdded,          
        JoystickRemoved,        
        JoystickBatteryUpdated,
        JoystickUpdateComplete,
        GamepadAxisMotion, 
        GamepadButtonDown,         
        GamepadButtonUp,           
        GamepadAdded,               
        GamepadRemoved,             
        GamepadRemapped,            
        GamepadTouchpadDown,       
        GamepadTouchpadMotion,     
        GamepadTouchpadUp,         
        GamepadSensorUpdate,       
        GamepadUpdateComplete,     
        GamepadSteamHandleUpdated,
        FingerDown,
        FingerUp,
        FingerMotion,
        FingerCanceled,
        ClipBoardUpdate,
        DropFile,
        DropText,    
        DropBegin,   
        DropComplete,
        DropPosition,
        AudioDeviceAdded,
        AudioDeviceRemoved,       
        AudioDeviceFormatChanged,
        SensorUpdate,
        PenProximityIn,
        PenProximityOut,
        PenDown,         
        PenUp,           
        PenButtonDown,  
        PenButtonUp,    
        PenMotion,       
        PenAxis,         
        CameraDeviceAdded,
        CameraDeviceRemoved, 
        CameraDeviceApproved,
        CameraDeviceDenied,  
        RenderTargetsReset,
        RenderDeviceRest,
        RenderDeviceLost,
        Private0,
        Private1,
        Private2,
        Private3,
        PollSentinel,
        User,
        Last
    };
}

#include <LittleEngine/Core/Platform/Event.inl>
