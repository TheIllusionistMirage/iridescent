#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Memory/Allocator.hpp"

// Start of Irideiscent's namespace
namespace Iridescent
{

// Start of System module's namespace
namespace System
{
    
// This struct is filled with system level
// info, e.g., architecture, etc.
struct Info
{
    bool m_32bit; // set to true if using a 32-bit system
    
    // add other such required stuff here...
    
    void initSystemInfo();
};

static Info SystemInfo;

// Forward declarations of the classes in the System module
    
// class Message;
// class MessageBus;
// 
// class MemoryPool;
// 
// class Window;
// class WindowImp;
// class Keyboard;
// class KeyboardImp;
// class Event;
// class EventImp;
// class Audio;
// class AudioImp;
// 
// class WindowManager;
// class InputManager;
// class AudioManager;
// class MemoryManager;

}
// End of System module's namespace

}
// End of Irideiscent's namespace

#endif // SYSTEM_HPP
