// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#include <stdexcept>
#include <LittleEngine/SDLBackend/SDLEventManagerImpl.hpp>
#include <SDL3/SDL_events.h>
#include <LittleEngine/Core/Event.hpp>

bool Le::SDLEventManagerImpl::PollEvent(Event& event) const
{
    SDL_Event sdlEvent;
    if (!SDL_PollEvent(&sdlEvent)) return false;

    switch (sdlEvent.type)
    {
        case SDL_EVENT_FIRST                             : event.eventType = EventType:: First                       ; break;
        case SDL_EVENT_QUIT                              : event.eventType = EventType:: Quit                        ; break;
        case SDL_EVENT_TERMINATING                       : event.eventType = EventType:: Terminating                 ; break;
        case SDL_EVENT_LOW_MEMORY                        : event.eventType = EventType:: LowMemory                   ; break;
        case SDL_EVENT_WILL_ENTER_BACKGROUND             : event.eventType = EventType:: WillEnterBackground         ; break;
        case SDL_EVENT_DID_ENTER_BACKGROUND              : event.eventType = EventType:: DidEnterBackground          ; break;
        case SDL_EVENT_WILL_ENTER_FOREGROUND             : event.eventType = EventType:: WillEnterForeground         ; break;
        case SDL_EVENT_DID_ENTER_FOREGROUND              : event.eventType = EventType:: DidEnterForeground          ; break;
        case SDL_EVENT_LOCALE_CHANGED                    : event.eventType = EventType:: LocaleChanged               ; break;
        case SDL_EVENT_SYSTEM_THEME_CHANGED              : event.eventType = EventType:: SystemThemeChanged          ; break;
        case SDL_EVENT_DISPLAY_ORIENTATION               : event.eventType = EventType:: DisplayOrientation          ; break;
        case SDL_EVENT_DISPLAY_ADDED                     : event.eventType = EventType:: DisplayAdded                ; break;
        case SDL_EVENT_DISPLAY_REMOVED                   : event.eventType = EventType:: DisplayRemoved              ; break;
        case SDL_EVENT_DISPLAY_MOVED                     : event.eventType = EventType:: DisplayMoved                ; break;
        case SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED      : event.eventType = EventType:: DisplayDesktopModeChanged   ; break;
        case SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED      : event.eventType = EventType:: DisplayCurrentModeChanged   ; break;
        case SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED     : event.eventType = EventType:: DisplayContentScaleChanged  ; break;
        // case SDL_EVENT_DISPLAY_FIRST                  : event.eventType = EventType:: DisplayFirst                ; break;
        // case SDL_EVENT_DISPLAY_LAST                   : event.eventType = EventType:: DisplayLast                 ; break;
        case SDL_EVENT_WINDOW_SHOWN                      : event.eventType = EventType:: WindowShown                 ; break;
        case SDL_EVENT_WINDOW_HIDDEN                     : event.eventType = EventType:: WindowHidden                ; break;
        case SDL_EVENT_WINDOW_EXPOSED                    : event.eventType = EventType:: WindowExposed               ; break;
        case SDL_EVENT_WINDOW_MOVED                      : event.eventType = EventType:: WindowMoved                 ; break;
        case SDL_EVENT_WINDOW_RESIZED                    : event.eventType = EventType:: WindowResized               ; break;
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED         : event.eventType = EventType:: WindowPixelSizeChanged      ; break;
        case SDL_EVENT_WINDOW_METAL_VIEW_RESIZED         : event.eventType = EventType:: WindowMetalViewResized      ; break;
        case SDL_EVENT_WINDOW_MINIMIZED                  : event.eventType = EventType:: WindowMinimized             ; break;
        case SDL_EVENT_WINDOW_MAXIMIZED                  : event.eventType = EventType:: WindowMaximized             ; break;
        case SDL_EVENT_WINDOW_RESTORED                   : event.eventType = EventType:: WindowRestored              ; break;
        case SDL_EVENT_WINDOW_MOUSE_ENTER                : event.eventType = EventType:: WindowMouseEnter            ; break;
        case SDL_EVENT_WINDOW_MOUSE_LEAVE                : event.eventType = EventType:: WindowMouseLeave            ; break;
        case SDL_EVENT_WINDOW_FOCUS_GAINED               : event.eventType = EventType:: WindowFocusGained           ; break;
        case SDL_EVENT_WINDOW_FOCUS_LOST                 : event.eventType = EventType:: WindowFocusLost             ; break;
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED            : event.eventType = EventType:: WindowCloseRequested        ; break;
        case SDL_EVENT_WINDOW_HIT_TEST                   : event.eventType = EventType:: WindowHitTest               ; break;
        case SDL_EVENT_WINDOW_ICCPROF_CHANGED            : event.eventType = EventType:: WindowICCProfChanged        ; break;
        case SDL_EVENT_WINDOW_DISPLAY_CHANGED            : event.eventType = EventType:: WindowDisplayChanged        ; break;
        case SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED      : event.eventType = EventType:: WindowDisplayScaleChanged   ; break;
        case SDL_EVENT_WINDOW_SAFE_AREA_CHANGED          : event.eventType = EventType:: WindowSafeAreaChanged       ; break;
        case SDL_EVENT_WINDOW_OCCLUDED                   : event.eventType = EventType:: WindowOccluded              ; break;
        case SDL_EVENT_WINDOW_ENTER_FULLSCREEN           : event.eventType = EventType:: WindowEnterFullscreen       ; break;
        case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN           : event.eventType = EventType:: WindowLeaveFullscreen       ; break;
        case SDL_EVENT_WINDOW_DESTROYED                  : event.eventType = EventType:: WindowDestroyed             ; break;
        case SDL_EVENT_WINDOW_HDR_STATE_CHANGED          : event.eventType = EventType:: WindowHDRStateChanged       ; break;
        // case SDL_EVENT_WINDOW_FIRST                   : event.eventType = EventType:: WindowFirst                 ; break;
        // case SDL_EVENT_WINDOW_LAST                    : event.eventType = EventType:: WindowLast                  ; break;
        case SDL_EVENT_KEY_DOWN                          : event.eventType = EventType:: KeyDown                     ; break;
        case SDL_EVENT_KEY_UP                            : event.eventType = EventType:: KeyUp                       ; break;
        case SDL_EVENT_TEXT_EDITING                      : event.eventType = EventType:: TextEditing                 ; break;
        case SDL_EVENT_TEXT_INPUT                        : event.eventType = EventType:: TextInput                   ; break;
        case SDL_EVENT_KEYMAP_CHANGED                    : event.eventType = EventType:: KeymapChanged               ; break;
        case SDL_EVENT_KEYBOARD_ADDED                    : event.eventType = EventType:: KeyboardAdded               ; break;
        case SDL_EVENT_KEYBOARD_REMOVED                  : event.eventType = EventType:: KeyboardRemoved             ; break;
        case SDL_EVENT_TEXT_EDITING_CANDIDATES           : event.eventType = EventType:: TextEditingCandidates       ; break;
        case SDL_EVENT_MOUSE_MOTION                      : event.eventType = EventType:: MouseMotion                 ; break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN                 : event.eventType = EventType:: MouseButtonDown             ; break;
        case SDL_EVENT_MOUSE_BUTTON_UP                   : event.eventType = EventType:: MouseButtonUp               ; break;
        case SDL_EVENT_MOUSE_WHEEL                       : event.eventType = EventType:: MouseWheel                  ; break;
        case SDL_EVENT_MOUSE_ADDED                       : event.eventType = EventType:: MouseAdded                  ; break;
        case SDL_EVENT_MOUSE_REMOVED                     : event.eventType = EventType:: MouseRemoved                ; break;
        case SDL_EVENT_JOYSTICK_AXIS_MOTION              : event.eventType = EventType:: JoystickAxisMotion          ; break;
        case SDL_EVENT_JOYSTICK_BALL_MOTION              : event.eventType = EventType:: JoystickBallMotion          ; break;
        case SDL_EVENT_JOYSTICK_HAT_MOTION               : event.eventType = EventType:: JoystickHatMotion           ; break;
        case SDL_EVENT_JOYSTICK_BUTTON_DOWN              : event.eventType = EventType:: JoystickButtonDown          ; break;
        case SDL_EVENT_JOYSTICK_BUTTON_UP                : event.eventType = EventType:: JoystickButtonUp            ; break;
        case SDL_EVENT_JOYSTICK_ADDED                    : event.eventType = EventType:: JoystickAdded               ; break;
        case SDL_EVENT_JOYSTICK_REMOVED                  : event.eventType = EventType:: JoystickRemoved             ; break;
        case SDL_EVENT_JOYSTICK_BATTERY_UPDATED          : event.eventType = EventType:: JoystickBatteryUpdated      ; break;
        case SDL_EVENT_JOYSTICK_UPDATE_COMPLETE          : event.eventType = EventType:: JoystickUpdateComplete      ; break;
        case SDL_EVENT_GAMEPAD_AXIS_MOTION               : event.eventType = EventType:: GamepadAxisMotion           ; break;
        case SDL_EVENT_GAMEPAD_BUTTON_DOWN               : event.eventType = EventType:: GamepadButtonDown           ; break;
        case SDL_EVENT_GAMEPAD_BUTTON_UP                 : event.eventType = EventType:: GamepadButtonUp             ; break;
        case SDL_EVENT_GAMEPAD_ADDED                     : event.eventType = EventType:: GamepadAdded                ; break;
        case SDL_EVENT_GAMEPAD_REMOVED                   : event.eventType = EventType:: GamepadRemoved              ; break;
        case SDL_EVENT_GAMEPAD_REMAPPED                  : event.eventType = EventType:: GamepadRemapped             ; break;
        case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN             : event.eventType = EventType:: GamepadTouchpadDown         ; break;
        case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION           : event.eventType = EventType:: GamepadTouchpadMotion       ; break;
        case SDL_EVENT_GAMEPAD_TOUCHPAD_UP               : event.eventType = EventType:: GamepadTouchpadUp           ; break;
        case SDL_EVENT_GAMEPAD_SENSOR_UPDATE             : event.eventType = EventType:: GamepadSensorUpdate         ; break;
        case SDL_EVENT_GAMEPAD_UPDATE_COMPLETE           : event.eventType = EventType:: GamepadUpdateComplete       ; break;
        case SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED      : event.eventType = EventType:: GamepadSteamHandleUpdated   ; break;
        case SDL_EVENT_FINGER_DOWN                       : event.eventType = EventType:: FingerDown                  ; break;
        case SDL_EVENT_FINGER_UP                         : event.eventType = EventType:: FingerUp                    ; break;
        case SDL_EVENT_FINGER_MOTION                     : event.eventType = EventType:: FingerMotion                ; break;
        case SDL_EVENT_FINGER_CANCELED                   : event.eventType = EventType:: FingerCanceled              ; break;
        case SDL_EVENT_CLIPBOARD_UPDATE                  : event.eventType = EventType:: ClipBoardUpdate             ; break;
        case SDL_EVENT_DROP_FILE                         : event.eventType = EventType:: DropFile                    ; break;
        case SDL_EVENT_DROP_TEXT                         : event.eventType = EventType:: DropText                    ; break;
        case SDL_EVENT_DROP_BEGIN                        : event.eventType = EventType:: DropBegin                   ; break;
        case SDL_EVENT_DROP_COMPLETE                     : event.eventType = EventType:: DropComplete                ; break;
        case SDL_EVENT_DROP_POSITION                     : event.eventType = EventType:: DropPosition                ; break;
        case SDL_EVENT_AUDIO_DEVICE_ADDED                : event.eventType = EventType:: AudioDeviceAdded            ; break;
        case SDL_EVENT_AUDIO_DEVICE_REMOVED              : event.eventType = EventType:: AudioDeviceRemoved          ; break;
        case SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED       : event.eventType = EventType:: AudioDeviceFormatChanged    ; break;
        case SDL_EVENT_SENSOR_UPDATE                     : event.eventType = EventType:: SensorUpdate                ; break;
        case SDL_EVENT_PEN_PROXIMITY_IN                  : event.eventType = EventType:: PenProximityIn              ; break;
        case SDL_EVENT_PEN_PROXIMITY_OUT                 : event.eventType = EventType:: PenProximityOut             ; break;
        case SDL_EVENT_PEN_DOWN                          : event.eventType = EventType:: PenDown                     ; break;
        case SDL_EVENT_PEN_UP                            : event.eventType = EventType:: PenUp                       ; break;
        case SDL_EVENT_PEN_BUTTON_DOWN                   : event.eventType = EventType:: PenButtonDown               ; break;
        case SDL_EVENT_PEN_BUTTON_UP                     : event.eventType = EventType:: PenButtonUp                 ; break;
        case SDL_EVENT_PEN_MOTION                        : event.eventType = EventType:: PenMotion                   ; break;
        case SDL_EVENT_PEN_AXIS                          : event.eventType = EventType:: PenAxis                     ; break;
        case SDL_EVENT_CAMERA_DEVICE_ADDED               : event.eventType = EventType:: CameraDeviceAdded           ; break;
        case SDL_EVENT_CAMERA_DEVICE_REMOVED             : event.eventType = EventType:: CameraDeviceRemoved         ; break;
        case SDL_EVENT_CAMERA_DEVICE_APPROVED            : event.eventType = EventType:: CameraDeviceApproved        ; break;
        case SDL_EVENT_CAMERA_DEVICE_DENIED              : event.eventType = EventType:: CameraDeviceDenied          ; break;
        case SDL_EVENT_RENDER_TARGETS_RESET              : event.eventType = EventType:: RenderTargetsReset          ; break;
        case SDL_EVENT_RENDER_DEVICE_RESET               : event.eventType = EventType:: RenderDeviceRest            ; break;
        case SDL_EVENT_RENDER_DEVICE_LOST                : event.eventType = EventType:: RenderDeviceLost            ; break;
        case SDL_EVENT_PRIVATE0                          : event.eventType = EventType:: Private0                    ; break;
        case SDL_EVENT_PRIVATE1                          : event.eventType = EventType:: Private1                    ; break;
        case SDL_EVENT_PRIVATE2                          : event.eventType = EventType:: Private2                    ; break;
        case SDL_EVENT_PRIVATE3                          : event.eventType = EventType:: Private3                    ; break;
        case SDL_EVENT_POLL_SENTINEL                     : event.eventType = EventType:: PollSentinel                ; break;
        case SDL_EVENT_USER                              : event.eventType = EventType:: User                        ; break;
        case SDL_EVENT_LAST                              : event.eventType = EventType:: Last                        ; break;
    default:
        throw std::runtime_error("EventManager : Unhandled event type");
    }

    return true;
}
