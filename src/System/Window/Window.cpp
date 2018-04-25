#include "System/Window/Window.hpp"

namespace Iridescent
{

namespace System
{

namespace Window
{

bool Window::create( const Types::UInt16 width,
                     const Types::UInt16 height,
                     const Types::UInt16 bpp,
                     const std::string& title,
                     const Style style )
{
    // stub
    m_imp.create( width, height, bpp, title, style );
}

///////////////////////////////////////////////////////////////////////////////

void Window::destroy()
{
    // stub
    m_imp.destroy();
}

///////////////////////////////////////////////////////////////////////////////

bool Window::isOpen()
{
    // stub
    m_imp.isOpen();
}

///////////////////////////////////////////////////////////////////////////////

void Window::addEventHandler( Event::Handler* handler )
{
    m_handler = handler;
    m_imp.addEventHandler( handler );
}

///////////////////////////////////////////////////////////////////////////////

void Window::updateEvents()
{
    if ( isOpen() )
    {
        m_imp.updateEvents();
    }
}

///////////////////////////////////////////////////////////////////////////////

void Window::clear()
{
    m_imp.clear();
}

///////////////////////////////////////////////////////////////////////////////

void Window::display()
{
    m_imp.display();
}

///////////////////////////////////////////////////////////////////////////////

} // End of namespace Window

} // End of namespace System

} // End of namespace Iridescent
