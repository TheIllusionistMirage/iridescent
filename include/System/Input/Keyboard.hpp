#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

//#include "System/Event/Imp/KeyboardImp.hpp"
#include "System/Input/Imp/KeyboardImp.hpp"

namespace Iridescent
{

namespace System
{

namespace Keyboard
{

// Keyboard is a static class that encapsulates the keyboard in the system
struct Keyboard
{   
    // Returns true if the specified key is currently down
    // NOTE: Use this for real time keyboard input handling,
    // just like SFML
    static bool isKeyDown( const Key key )
    {
        return KeyboardImp::isKeyDown( key );
    }

};

} // End of namespace Keyboard

} // End of namespace System

} // End of namespace Iridescent

#endif // KEYBOARD_HPP
