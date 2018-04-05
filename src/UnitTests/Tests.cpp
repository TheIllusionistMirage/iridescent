/**
 * All unit tests go here
 */

#include <iostream>
#include <chrono>

#include "UnitTests/Tests.hpp"

// System module
#include "System/Memory/Pool.hpp"

// Core module
#include "Core/StringHelper.hpp"

#include "System/Types.hpp"

///////////////////////////////////////////////////////////////////////////////
// Run all tests
///////////////////////////////////////////////////////////////////////////////

void runAllTests()
{
    std::cout << "* Checking architecture..." << std::endl;
    std::cout << ( sizeof(void*) == 4 ? 32 : 64 ) << "-bit architecture detected." << std::endl;
    
    std::cout << "* Checking integer type sizes..." << std::endl;
    
    std::cout << "Size of 8-bit unsigned int: " << sizeof(Iridescent::System::Types::UInt8) << std::endl;
    std::cout << "Size of 8-bit signed int: " << sizeof(Iridescent::System::Types::Int8) << std::endl;
    std::cout << "Size of 16-bit unsigned int: " << sizeof(Iridescent::System::Types::UInt16) << std::endl;
    std::cout << "Size of 16-bit signed int: " << sizeof(Iridescent::System::Types::Int16) << std::endl;
    std::cout << "Size of 32-bit unsigned int: " << sizeof(Iridescent::System::Types::UInt32) << std::endl;
    std::cout << "Size of 32-bit signed int: " << sizeof(Iridescent::System::Types::Int32) << std::endl;
    std::cout << "Size of 64-bit unsigned int: " << sizeof(Iridescent::System::Types::UInt64) << std::endl;
    std::cout << "Size of 64-bit signed int: " << sizeof(Iridescent::System::Types::Int64) << std::endl;
    
    if ( !testMemoryPool() )
        std::cout << "[FAILED TEST] Problem in submodule `MemoryPool`" << std::endl;
    else
        std::cout << "[SUCCEEDED TEST] Submodule `MemoryPool`" << std::endl;
    
    if ( !testStringHelper() )
        std::cout << "[FAILED TEST] Problem in submodule `StringHelper`" << std::endl;
    else
        std::cout << "[SUCCEEDED TEST] Submodule `StringHelper`" << std::endl;
}


///////////////////////////////////////////////////////////////////////////////
// Module: System
// Submodule: Memory
///////////////////////////////////////////////////////////////////////////////
bool testMemoryPool()
{
    std::cout << "* Analyzing performance of the memory pool..." << std::endl;
    
    Iridescent::System::Memory::Pool::get().create();
    
    std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
    
    struct MyStruct
    {
        int i;
        float f;
    };
    
    for ( long long i = 0; i < 10000; ++i )
    {
        MyStruct* arr = (MyStruct* )Iridescent::System::Memory::Pool::get().allocate( sizeof(MyStruct) * 100 );
        
        for ( long long j = 0; j < 1000; ++j )
        {
            MyStruct* arr2 = (MyStruct* )Iridescent::System::Memory::Pool::get().allocate( sizeof(MyStruct) * 100 );
            
            Iridescent::System::Memory::Pool::get().deallocate( arr2 );
        }
        
        Iridescent::System::Memory::Pool::get().deallocate( arr );
    }
    
    std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();
    
    std::chrono::milliseconds dt = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime );
    std::cout << "Total Time (memory pool): " << dt.count() << " ms" << std::endl;
    
    // C++ default memory manager (new/delete)
    
    startTime = std::chrono::system_clock::now();
    
    for ( long long i = 0; i < 10000; ++i )
    {
        MyStruct* arr = new MyStruct[100];
        
        for ( long long j = 0; j < 1000; ++j )
        {
            MyStruct* arr2 = new MyStruct[100];
            delete[] arr2;
        }
        
        delete[] arr;
    }
    
    endTime = std::chrono::system_clock::now();
    
    dt = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime );
    std::cout << "Total Time (new/delete): " << dt.count() << " ms" << std::endl;
    
    // C memory manager (malloc/free)
    
    startTime = std::chrono::system_clock::now();
    
    for ( long long i = 0; i < 10000; ++i )
    {
        MyStruct* arr = (MyStruct* ) malloc( sizeof( MyStruct ) * 100 );
        
        for ( long long j = 0; j < 1000; ++j )
        {
            MyStruct* arr2 = (MyStruct* ) malloc( sizeof( MyStruct ) * 100 );
            free(arr2);
        }
        
        free(arr);
    }
    
    endTime = std::chrono::system_clock::now();
    
    dt = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime );
    std::cout << "Total Time (malloc/free): " << dt.count() << " ms" << std::endl;
    
    Iridescent::System::Memory::Pool::get().destroy();
    
    return true;
}


///////////////////////////////////////////////////////////////////////////////
// Module: Core
// Submodule: StringHelper
///////////////////////////////////////////////////////////////////////////////


bool testStringHelper()
{
    std::string str1 = "Hello, World!";
    std::string str2 = "  \n   \b\t";
    
    if ( Iridescent::Core::String::isWhitespace( str1 ) )
        return false;
    
    if ( !Iridescent::Core::String::isWhitespace( str2 ) )
        return false;
    
    const std::string ref = "Hello, World!";
    std::string str3 = "  \n  Hello, World!\b\t";
    
    Iridescent::Core::String::trim( str3 );
    
    if ( ref != str3 )
        return false;
    
    str3 = "  \n  Hello, World!";
    Iridescent::Core::String::ltrim( str3 );
    
    if ( ref != str3 )
        return false;
    
    str3 = "Hello, World!\b\t";
    Iridescent::Core::String::rtrim( str3 );
    
    if ( ref != str3 )
        return false;
    
    return true;
}
