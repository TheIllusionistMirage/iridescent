#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "System/Event/Imp/KeyboardImp.hpp"

namespace Iridescent
{

namespace System
{

namespace Keyboard
{

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
