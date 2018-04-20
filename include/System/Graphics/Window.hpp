#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "System/Types.hpp"
#include "Imp/WindowImp.hpp"

namespace Iridescent
{

namespace System
{

namespace Graphics
{

class Window
{

public:
    
    // Used for setting the window porperties (e.g. is the window resizable)
    enum Style
    {
        None       = 0,
        Titlebar   = 1 << 0,
        Resize     = 1 << 1,
        Close      = 1 << 2,
        Fullscreen = 1 << 3,
        Default    = Titlebar | Resize | Close
    };
    
public:
    
    bool create( const Types::UInt16 width,
                 const Types::UInt16 height,
                 const Types::UInt16 bpp,
                 const std::string& title,
                 const Style style );
    
    void destroy();
    
    bool isOpen();
    
    
    
private:
    
    // The Window implementation
    WindowImp m_imp;

};

} // End of namespace Graphics

} // End of namespace System

} // End of namespace Iridescent

#endif // WINDOW_HPP
