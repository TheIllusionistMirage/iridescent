#include <SFML/Window/Event.hpp>

#include "System/Window/Imp/WindowImp.hpp"

namespace Iridescent
{

namespace System
{

namespace Window
{

WindowImp::WindowImp()
{
    m_windowHandle = new sf::RenderWindow;
}

WindowImp::~WindowImp()
{
    delete m_windowHandle;
}

bool WindowImp::create( const Types::UInt16 width,
                        const Types::UInt16 height,
                        const Types::UInt16 bpp,
                        const std::string& title,
                        const Style style )
{
    if ( !m_windowHandle )
        return false;
    
    m_windowHandle->create( sf::VideoMode( width, height, bpp ), title, static_cast<sf::Uint32>( style ) );
    
    return true;
}

///////////////////////////////////////////////////////////////////////////////

void WindowImp::destroy()
{
    m_windowHandle->close();
}

///////////////////////////////////////////////////////////////////////////////

bool WindowImp::isOpen()
{
    // stub
    return m_windowHandle->isOpen();
}

///////////////////////////////////////////////////////////////////////////////

void WindowImp::addEventHandler( Event::Handler* handler )
{
    m_handler = handler;
}

///////////////////////////////////////////////////////////////////////////////

void WindowImp::updateEvents()
{
    // Detect the events    
    sf::Event event;
    while( m_windowHandle->pollEvent( event ) )
    {
        Event::Event lastEvent;
        
        switch ( event.type )
        {
            case sf::Event::Closed:
            {
                lastEvent.type = Event::Event::EventType::Closed;
                m_eventQueue.push( lastEvent );
            } break;
            
            case sf::Event::KeyPressed:
            {
                lastEvent.type = Event::Event::EventType::KeyPressed;
                //lastEvent.data.key;
                Keyboard::Key code = static_cast<Keyboard::Key>( event.key.code );
                lastEvent.data.key.code = code;
                m_eventQueue.push( lastEvent );
            } break;
        }
    }
    
    // Handle the events
    while ( !m_eventQueue.empty() )
    {
        auto e = m_eventQueue.front();
        m_eventQueue.pop();
        
        switch ( e.type )
        {
            case Event::Event::EventType::Closed:
            {
                m_handler->handle( Event::Event::EventType::Closed );
            } break;
            
            case Event::Event::EventType::KeyPressed:
            {
                m_handler->handle( Event::Event::EventType::KeyPressed );
            } break;
            
            case Event::Event::EventType::KeyReleased:
            {
                
            } break;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

void WindowImp::clear()
{
    m_windowHandle->clear();
}

///////////////////////////////////////////////////////////////////////////////

void WindowImp::display()
{
    m_windowHandle->display();
}

///////////////////////////////////////////////////////////////////////////////

std::queue<Event::Event>* WindowImp::getEventQueue()
{
    return &m_eventQueue;
}

///////////////////////////////////////////////////////////////////////////////

} // End of namespace Graphics

} // End of namespace System

} // End of namespace Iridescent
