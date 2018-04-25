#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include <map>
#include <functional>
#include <algorithm>
#include <utility>
#include <memory>

#include "System/Event/Event.hpp"
//#include "System/Window/Window.hpp"

namespace Iridescent
{

namespace System
{

namespace Event
{

class Handler
{

public:
    
    Handler(){}
    
    ~Handler(){}
    
//     template <class Type, class ReturnType, class... Args>
//     void bindCallback( Event::EventType event, CallbackClassMethod<Type, ReturnType, Args...> callback )
//     {
//         //m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<Callback<Type, ReturnType, Args...>>>( event, &callback ) );
//         //m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<CallbackClassMethod<Type, ReturnType, Args...>>>( event, callback ) );
//         //m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<CallbackClassMethod<ReturnType, Args...>>>( event, std::make_shared<CallbackClassMethod<Type, ReturnType, Args...>>( callback ) ) );
//         //m_callbacks[event] = std::make_shared<Callback<Type, ReturnType, Args...>>( callback );
//         
//         m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<CallbackClassMethod<Type, ReturnType, Args...>>>( event, std::make_shared<CallbackClassMethod<Type, ReturnType, Args...>>( callback ) ) );
//     }
    
    template <class Type, class ReturnType = void, class... Args>
    void bindCallback( Event::EventType event, Type* object, typename CallbackClassMethod<Type, ReturnType, Args...>::Method method, Args... args )
    {
        m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<CallbackClassMethod<Type, ReturnType, Args...>>>( event, std::make_shared<CallbackClassMethod<Type, ReturnType, Args...>>( object, method, args... ) ) );
    }
    
    template <class ReturnType = void, class... Args>
    void bindCallback( Event::EventType event, typename CallbackFunction<ReturnType, Args...>::Function function, Args... args )
    {
        m_callbacks.insert( std::pair<Event::EventType, std::shared_ptr<CallbackFunction<ReturnType, Args...>>>( event, std::make_shared<CallbackFunction<ReturnType, Args...>>( function, args... ) ) );
    }
    
//     template <class Type, class ReturnType, class... Args>
//     void unbindCallback( Event::EventType event, Callback<Type, ReturnType, Args...> callback )
//     {
//     }
    
    void handle( const Event::EventType eventType )
    {
        //std::cout << "Event type: " << static_cast<int>( eventType ) << std::endl;
        
        auto range = m_callbacks.equal_range( eventType );
        std::for_each( range.first, range.second, []( const std::pair<const Event::Event::EventType,
                                                      std::shared_ptr<CallbackBase>> p )
                                                    { p.second->run(); } );
    }
    
    void handleAll()
    {
        for ( auto&& cb : m_callbacks )
        {
            cb.second->run();
        }
    }
    
    //void bindToWindow( Window::Window* window );

private:
    
//     template <class Type, class ReturnType, class... Args>
//     std::multimap<Event::Event::EventType, Callback<Type, ReturnType, Args...>> m;
    
    std::multimap<Event::Event::EventType, std::shared_ptr<CallbackBase>> m_callbacks;
    //std::map<Event::Event::EventType, std::shared_ptr<CallbackBase>> m_callbacks;
    
    //Window::Window m_window;
};

} // End of namespace Event

} // End of namespace System

} // End of namespace Iridescent

#endif // EVENT_HANDLER_HPP
