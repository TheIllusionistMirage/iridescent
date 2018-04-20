#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <tuple>
#include <utility>
#include <functional>
#include <typeinfo>

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

class CallbackBase
{
public:
    CallbackBase()
    {}
    
    ~CallbackBase()
    {}
    
    virtual void run() = 0;
};

// Courtesy: http://www.partow.net/programming/templatecallback/index.html

template <class Type, class ReturnType = void, class... Args>
class CallbackClassMethod : public CallbackBase
{

public:
    
    using Method = ReturnType (Type::*)( Args ... );
    using Params = std::tuple<Args...>;
    
    // TODO: Error checking
    
    CallbackClassMethod( Type* object, Method method, Args... args ) :
     m_object( object ),
     m_method( method ),
     m_params( args... )
    {
    }

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

///////////////////////////////////////////////////////////////////////////////
template <class ReturnType = void, class... Args>
class CallbackFunction : public CallbackBase
{

public:
    
    using Function = ReturnType (*)( Args ... );
    using Params = std::tuple<Args...>;
    
    // TODO: Error checking
    
    CallbackFunction( Function function, Args... args ) :
     m_function( function ),
     m_params( args... )
    {
    }

    void run() override
    {
        executeHelper( m_params, std::index_sequence_for<Args...>() );
    }

    ReturnType execute( Args... args )
    {
        return m_function( args... );
    }
    
private:
    
    template <std::size_t... Is>
    ReturnType executeHelper( Params& params, std::index_sequence<Is...> )
    {
        return execute( std::get<Is>( params )... );
    }
    
private:
    
    Function m_function;
    Params m_params;
};

// Courtesy: http://www.partow.net/programming/templatecallback/index.html
// template <class Type = void, class ReturnType = void, class... Args>
// class Callback : public CallbackBase
// {
// 
// public:
//     
//     using Method = ReturnType (Type::*)( Args ... );
//     using Function = ReturnType(*)(Args...);
//     using Params = std::tuple<Args...>;
//     
//     // TODO: Error checking
//     
//     Callback( Type* object, Method method, Args... args ) :
//      m_object( object ),
//      m_method( method ),
//      m_params( args... )
//     {
// //         if ( typeid(m_object) != typeid( void ) )
// //             m_method._method = method;
// //         else
// //             m_method._function = method;
//         //std::cout << "CLASS_METHOD: " << static_cast<const int>( CLASS_METHOD ) << std::endl;
//     }
// 
//     void run() override
//     {
//         executeHelper( m_params, std::index_sequence_for<Args...>() );
//     }
// 
//     ReturnType execute( Args... args )
//     {
// //         if ( typeid(m_object) != typeid( void ) )
// //             return (m_object->*m_method._method)( args... );
// //         else
// //             return m_method._function( args... );
// //         //else
// //             //return m_method( args... );
//         return (m_object->*m_method)( args... );
//     }
//     
// private:
//     
//     template <std::size_t... Is>
//     ReturnType executeHelper( Params& params, std::index_sequence<Is...> )
//     {
//         return execute( std::get<Is>( params )... );
//     }
//     
// private:
//     
//     Type* m_object;
// //     union
// //     {
// //         Method _method;
// //         Function _function;
// //     } m_method;
//     Method m_method;
//     Params m_params;
// };

// template <class ReturnType, class... Args>
// class Callback : public CallbackBase
// {
// 
// public:
//     
//     //using Method = ReturnType (Type::*)( Args ... );
//     using Function = ReturnType(*)(Args...);
//     //using Method = std::function<ReturnType(const Type&, Args...)>;
//     //using Function = std::function<ReturnType(Args...)>;
//     using Params = std::tuple<Args...>;
//     
//     union Callable
//     {
//         //Method   _method;
//         Function _function;
//     };
//     
//     // TODO: Error checking
//     
//     Callback( Function function = nullptr, Args... args ) :
//      m_params( args... )
//     {
//         //if ( typeid( Type ) == typeid( void ) )
//             m_callable._function = function;
//     }
//     
// //     Callback( Type* object = nullptr, Method method = nullptr, Args... args ) :
// //      m_object( object ),
// //      m_params( args... )
// //     {
// //         if ( typeid( Type ) != typeid( void ) )
// //             m_callable._method = method;
// //     }
// 
//     void run() override
//     {
//         executeHelper( m_params, std::index_sequence_for<Args...>() );
//     }
// 
//     ReturnType execute( Args... args )
//     {
//         //return (m_object->*m_method)( args... );
//         //if ( typeid( Type ) == typeid( void ) )
//             return m_callable._function( args... );
//         //return (m_object->*m_callable._method)( args... );
//     }
//     
// private:
//     
//     template <std::size_t... Is>
//     ReturnType executeHelper( Params& params, std::index_sequence<Is...> )
//     {
//         return execute( std::get<Is>( params )... );
//     }
//     
// private:
//     
//     Callable m_callable;
//     Params m_params;
// };

} // End of of namespace Event

} // End of of namespace System

} // End of of namespace Iridescent

#endif // EVENT_HPP
