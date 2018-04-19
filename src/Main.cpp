// #include <iostream>

#include "System/Log.hpp"
 #include "System/System.hpp"
// 
// #include "System/Memory/Pool.hpp"
// #include "Core/Types.hpp"

#include "UnitTests/Tests.hpp"

int main(int argc, char **argv)
{
    //runAllTests();
    
    // Initialize logging subsystem
    
    Iridescent::System::Log::get().setLevel( Iridescent::System::Log::Level::Debug );
    Iridescent::System::Log::get().setLogStream( std::cout );
    
    LOG(Iridescent::System::Log::Level::Info) << "Initialized Logging subsystem, Hello World!" << std::endl;
    
    // Determine system info
    Iridescent::System::SystemInfo.initSystemInfo();
    
    
    //Create the memory pool
    Iridescent::System::Memory::Pool::get().create();
    
    // Destroy the memory pool
    Iridescent::System::Memory::Pool::get().destroy();
    
    LOG(Iridescent::System::Log::Level::Info) << "Finished execution. Goodbye world." << std::endl;
    
    return 0;
}
