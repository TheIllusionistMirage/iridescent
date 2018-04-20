#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <tuple>

#include "System/Types.hpp"
#include "System/Event/Keyboard.hpp"
#include "System/Event/Mouse.hpp"

namespace Iridescent
{

namespace System
{

namespace Event
{

///////////////////////////////////////////////////////////////////////////////
// Events
// Courtesy: https://www.sfml-dev.org/documentation/2.4.2/Event_8hpp_source.php
///////////////////////////////////////////////////////////////////////////////

struct Event
{
    /////////////////////
    // Types of events //
    /////////////////////
    enum class EventType
    {
        None = 0,
        Closed,
        Resized,
        LostFocus,
        GainedFocus,
        KeyPressed,
        KeyReleased,
        MousePressed,
        MouseReleased,
        Count // The no. of event types
    };
    
    //////////////////////////////////////////////
    // Event data for the different event types //
    //////////////////////////////////////////////
    
    // Whenever the active Window is resized, the
    // new width and height are set here.
    struct SizeEvent
    {
        Types::UInt16 width;
        Types::UInt16 height;
    };
    
    // Whenever a keyboard event (a key was pressed or
    // released) occurs, the corresponding key's code is set.
    struct KeyEvent
    {
        Keyboard::Key code;
    };
    
    // Whenever a mouse button event (a mouse button was
    // pressed or released) occurs, the corresponding
    // button's code, and screen coordinates are set here.
    struct MouseButtonEvent
    {
        
    };
    
    
    // Event data is stored as a union because only the
    // event that last occurred, it's corresponding data
    // should be stored.
    
    union EventData
    {
        SizeEvent size;
        KeyEvent key;
        MouseButtonEvent mouseButton;
    };
    
    EventType type;
    EventData data;
};

///////////////////////////////////////////////////////////////////////////////
// Callback
///////////////////////////////////////////////////////////////////////////////

// // Courtesy: http://www.partow.net/programming/templatecallback/index.html
// class Callback
// {
// 
// public:
//     //using Method = ReturnType (Type::*)( Args ... );
//     
//     // TODO: Error checking
//     
//     Callback()
//     {}
//     
//     int (*v)(char);
//     
//     template <class Type, class ReturnType, class... Args>
//     void set( Type* obj, ReturnType(Type::*method)(Args...), Args... args )
//     {
//         static Type* m_object = obj;
//         static ReturnType(Type::*m_method)(Args...) = method;
//         
//         //(obj->*method)( args ... );
//         (m_object->*m_method)( args ... );
//     }
//     
//     void operator () ()
//     {
//     }
//     
//     
//     
// //     template <class Type, class ReturnType, class... Args>
// //     //Callback( Type* object, ReturnType(Type::*method)(Args...), Args... args ) //:
// //     //Callback( Type* object, ReturnType(Type::*), ReturnType returnType, Args... args )
// //     Callback( Type* object )
// // //      m_object( object ),
// // //      m_method( method )
// //     {
// //         //auto m = method;
// //     }
//     
// //     ReturnType operator () ( Args... args )
// //     {
// //         return (m_object->*m_method)( args... );
// //     }
// //     
// //     ReturnType execute( Args... args )
// //     {
// //         return operator()( args... );
// //     }
//     
// private:
//     
//     //Type* m_object;
//     //Method m_method;
// };

class CallbackBase
{
public:
    CallbackBase()
    {}
    
    ~CallbackBase()
    {}
    
    virtual void run() = 0;
//     {
//         std::cout << "asdasdasd" << std::endl;
//     }
};

// Courtesy: http://www.partow.net/programming/templatecallback/index.html
template <class Type, class ReturnType, class... Args>
class Callback : public CallbackBase
{

public:
    
    using Method = ReturnType (Type::*)( Args ... );
    using Params = std::tuple<Args...>;
    
    // TODO: Error checking
    
    Callback( Type* object, Method method, Args... args ) :
     m_object( object ),
     m_method( method ),
     m_params( args... )
    {}
    
//     ReturnType operator () ( Args... args )
//     {
//         return (m_object->*m_method)( args... );
//     }
//     
//     ReturnType execute( Args... args )
//     {
//         return operator()( args... );
//     }

    void run() override
    {
        executeHelper( m_params, std::index_sequence_for<Args...>() );
    }

    ReturnType execute( Args... args )
    {
        return (m_object->*m_method)( args... );
    }
    
private:
    
    template <std::size_t... Is>
    ReturnType executeHelper( Params& params, std::index_sequence<Is...> )
    {
        return execute( std::get<Is>( params )... );
    }
    
private:
    
    Type* m_object;
    Method m_method;
    Params m_params;
};

//template <typename Func, typename... BoundArgs>
//void connect(Func&& handler, const BoundArgs&&... args);

} // End of of namespace Event

} // End of of namespace System

} // End of of namespace Iridescent

#endif // EVENT_HPP
