#ifndef WINDOW_IMP_HPP
#define WINDOW_IMP_HPP

#include <queue>

#include <SFML/Graphics/RenderWindow.hpp>

#include "System/Types.hpp"
#include "System/Event/Event.hpp"
#include "System/Event/Handler.hpp"

namespace Iridescent
{

namespace System
{

namespace Window
{

// Used for setting the window porperties (e.g. is the window resizable)
enum class Style
{
    None       = 0,
    Titlebar   = 1 << 0,
    Resize     = 1 << 1,
    Close      = 1 << 2,
    Fullscreen = 1 << 3,
    Default    = Titlebar | Resize | Close
};


class WindowImp
{

public:
    
    WindowImp();
    
    ~WindowImp();
    
    bool create( const Types::UInt16 width,
                 const Types::UInt16 height,
                 const Types::UInt16 bpp,
                 const std::string& title,
                 const Style style );
    
    void destroy();
    
    bool isOpen();
    
    void addEventHandler( Event::Handler* handler );
    
    void updateEvents();
    
    // Render functions
    
    void clear();
    
    void display();
    
    std::queue<Event::Event>* getEventQueue();
    
private:
    
    sf::RenderWindow* m_windowHandle;
    std::queue<Event::Event> m_eventQueue;
    Event::Handler* m_handler;

};

} // End of namespace Graphics

} // End of namespace System

} // End of namespace Iridescent

#endif // WINDOW_IMP_HPP
