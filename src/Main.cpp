// #include <iostream>

#include "System/Log.hpp"
 #include "System/System.hpp"
// 
// #include "System/Memory/Pool.hpp"
#include "Core/Types.hpp"

#include "UnitTests/Tests.hpp"

int main(int argc, char **argv)
{
    //runAllTests();
    testWindow();
    
    // Initialize logging subsystem
    
//     Iridescent::System::Log::get().setLevel( Iridescent::System::Log::Level::Debug );
//     Iridescent::System::Log::get().setLogStream( std::cout );
//     
//     LOG(Iridescent::System::Log::Level::Info) << "Initialized Logging subsystem, Hello World!" << std::endl;
//     
//     // Determine system info
//     Iridescent::System::SystemInfo.initSystemInfo();
//     
//     
//     //Create the memory pool
//     Iridescent::System::Memory::Pool::get().create();
//     
//     // Destroy the memory pool
//     Iridescent::System::Memory::Pool::get().destroy();
//     
//     LOG(Iridescent::System::Log::Level::Info) << "Finished execution. Goodbye world." << std::endl;
    
    return 0;
}


//////////// 
// Stuff
////////////

//Iridescent::System::Event::Callback cb;
    
//     class MyStruct
//     {
//     public:
//         int i;
//         float f;
//         
//         MyStruct() :
//          i(0), f(0.f)
//         {}
//         
//         float add( int a, float* b )
//         {
//             std::cout << "This is your conscience: " << ( i + a ) + ( f + *b ) << std::endl;
//             return ( i + a ) + ( f + *b );
//         }
//     };
//     
//     int a = 10;
//     float b = 3.14;
//     MyStruct ms;
    
//     
//     //Iridescent::System::Event::Callback cb2( MyStruct, (&MyStruct::add)(int, float), 12, 32.4f );
//     //Iridescent::System::Event::Callback cb2;
//     //cb2.set<MyStruct, float, int, double>( &ms, &MyStruct::add, 1, 3.14 );
//     //cb2();
//     
//     a = 21;
//     b = 4.13;
//     
//     Iridescent::System::Event::Handler handler;
//     
//     //handler.bindCallback<MyStruct, float, int, float*>( Iridescent::System::Event::Event::EventType::Closed, Iridescent::System::Event::CallbackClassMethod<MyStruct, float, int, float*>( &ms, &MyStruct::add, a, &b ) );
//     //handler.bindCallback<MyStruct, float>( Iridescent::System::Event::Event::EventType::Closed, &ms, &MyStruct::add, a, &b );
//     handler.bindCallback<int>( Iridescent::System::Event::Event::EventType::Closed, &foo, 10 );
//     //handler.bindCallback( Iridescent::System::Event::Event::EventType::Closed, [](int x, float y){ std::cout << "Test lambda: " << x << ", " << y << std::endl; }, a, a + 3.14f );
//     
//     handler.handle();
    
//     Iridescent::System::Event::Callback<MyStruct, float, int, float*> cb( &ms, &MyStruct::add, a, &b );
//     //cb(1, 3.14);
//     //cb.execute(1, 3.14);
//     //cb();
//     cb.run();
//     
//     Iridescent::System::Event::Callback<int, int> cb2( &foo, 10 );
//     cb2.run();
    
//     Iridescent::System::Event::Handler handler;
//     handler.bindCallback<int, int>( Iridescent::System::Event::Event::EventType::Closed, &foo, 10 );
