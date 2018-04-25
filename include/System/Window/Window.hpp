#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include "System/Types.hpp"
#include "Imp/WindowImp.hpp"
#include "System/Event/Handler.hpp"

namespace Iridescent
{

namespace System
{

namespace Window
{

class Window
{

public:
    
    bool create( const Types::UInt16 width,
                 const Types::UInt16 height,
                 const Types::UInt16 bpp,
                 const std::string& title,
                 const Style style );
    
    void destroy();
    
    bool isOpen();
    
    void addEventHandler( Event::Handler* handler );
    
    void updateEvents();
    
    void clear();
    
    void display();
    
private:
    
    // The Window implementation
    WindowImp m_imp;
    Event::Handler* m_handler;
};

} // End of namespace Window

} // End of namespace System

} // End of namespace Iridescent

#endif // WINDOW_HPP
