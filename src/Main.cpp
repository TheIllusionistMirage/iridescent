// #include <iostream>

// #include "System/Log.hpp"
// #include "System/System.hpp"
// 
// #include "System/Memory/Pool.hpp"
// #include "Core/Types.hpp"

#include "UnitTests/Tests.hpp"

int main(int argc, char **argv)
{
    runAllTests();
    
    // Initialize logging subsystem
    
//     Iridescent::System::Log::get().setLevel( Iridescent::System::Log::Level::Debug );
//     Iridescent::System::Log::get().setLogStream( std::cout );
//     
//     LOG(Iridescent::System::Log::Level::Info) << "Initialized Logging subsystem, Hello World!" << std::endl;
//     
//     // Determine system info
//     Iridescent::System::SystemInfo.initSystemInfo();
    
    
    
    // Create the memory pool
//     Iridescent::System::Memory::Pool::get().create();
//     
//     {
//         Iridescent::Core::Types::Map<int, std::string> myMap;
//         myMap[0] = "Hello";
//         myMap[1] = "World";
//         myMap[2] = "!";
//         
//         for ( auto&& e : myMap )
//             std::cout << e.first << ", " << e.second << std::endl;
//         
//         Iridescent::Core::Types::String str;
//         //std::cout << str << std::endl;
//         str = "instead (§31.2.2.1). The sequence of an unordered container does not have a guaranteed order. A multimap differs from a map in that a key value may occur many times. Container adaptors are containers providing specialized interfaces to other contaiHello, World!";
//         //std::cout << str << std::endl;
//         str += "instead (§31.2.2.1). The sequence of an unordered container does not have a guaranteed order. A multimap differs from a map in that a key value may occur many times. Container adaptors are containers providing specialized interfaces to other contaiHello, World!";
//         //str = "";
//         //std::cout << str << std::endl;
//     }
//     
//     // Destroy the memory pool
//     Iridescent::System::Memory::Pool::get().destroy();
    
//     std::chrono::duration<int, std::ratio<60>> oneMin(1);
//     std::chrono::duration<int> tenSec(10);
//     
//     std::cout << (tenSec < oneMin) << std::endl;
//     
//     std::chrono::system_clock clock;
//     std::cout << clock.is_steady << std::endl;
//     std::chrono::system_clock::time_point tp;// =  std::chrono::system_clock::now();
//     //std::cout << tp.time_since_epoch().count() << std::endl;
//     std::time_t t = std::chrono::system_clock::to_time_t( tp );
//     std::string tstr = std::asctime( gmtime( &t ) );
//     std::cout << "Epoch: " << tstr << std::endl;
//     
//     tp =  std::chrono::system_clock::now();
//     t = std::chrono::system_clock::to_time_t( tp );
//     tstr = std::asctime( gmtime( &t ) );
//     std::cout << "Now: " << tstr << std::endl;
//     
//     std::chrono::system_clock::time_point tp1 =  std::chrono::system_clock::time_point::min();
//     std::time_t t1 = std::chrono::system_clock::to_time_t( tp1 );
//     tstr = std::asctime( gmtime( &t1 ) );
//     std::cout << "Min: " << tstr << std::endl;
//     
// //     std::chrono::duration<long long, std::ratio<1, 1000>> ms = std::chrono::duration_cast<std::chrono::duration<long long, std::ratio<1, 1000>>>( tp - tp1 );
// //     std::time_t t2 = std::chrono::system_clock::to_time_t( ms );
//     auto td = t - t1;
//     std::time_t t2 = std::chrono::system_clock::to_time_t( td );
//     tstr = std::asctime( gmtime( &t2 ) );
//     std::cout << "Diff: " << tstr << std::endl;
//     
//     tp =  std::chrono::system_clock::time_point::max();
//     t = std::chrono::system_clock::to_time_t( tp );
//     tstr = std::asctime( gmtime( &t ) );
//     std::cout << "Max: " << tstr << std::endl;
    
//     std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();
//     
//     for ( auto i = 0; i < 10000; ++i )
//     {
//         for ( auto j = 0; j < 1000; ++j )
//         {}
//     }
//     
//     std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();
//     
//     std::chrono::milliseconds dt = std::chrono::duration_cast<std::chrono::milliseconds>( endTime - startTime );
//     std::cout << dt.count() << std::endl;
    
    return 0;
}

// //     {
// //         struct MyStruct
// //         {
// //             int a;
// //             char b;
// //             double c;
// //             
// //             MyStruct(int _a, char _b, double _c) : a(_a), b(_b), c(_c)
// //             {}
// //         };
// //         
// //         Iridescent::Core::Types::Vector<MyStruct> vec;
// //         int i = 0;
// //         int j = 'a';
// //         double k = 1.58;
// //         for ( ; i < 50 && j < 'a' + 50 && k < 1.58 + 80; ++i, ++j, k += 0.56 )
// //             vec.push_back( MyStruct(i, j, k) );
// //         
// //         std::cout << "Created vector" << std::endl;
// //         
// //         auto bl = Iridescent::System::Memory::Pool::get().getBlock<4>();
// //         bl->printAll();
// //         
// //         Iridescent::Core::Types::List<int> l;
// //         for ( auto i = 1; i <= 5; ++i )
// //         {
// //             //MyStruct* arr = (MyStruct*)Iridescent::System::Memory::Pool::get().allocate( sizeof(MyStruct) * i );
// //             //Iridescent::System::Memory::Pool::get().deallocate( arr );
// //             l.push_back( i );
// //             //std::cout << "Z" << std::endl;
// //         }
// //                 
// //         std::cout << "Created list" << std::endl;
// //         
// //         bl->printAll();
// //         
// //         for ( auto&& e : l )
// //             std::cout << e << std::endl;
// //         std::cout << std::endl;
// //         
// //         l.clear();
// // //         for ( auto i = 1; i <= 5; ++i )
// // //             l.pop_back();
// //         
// //         bl->printAll();
// //         
// //         std::cout << "list popped" << std::endl;
// //     }
//
//     
// //     Iridescent::System::Memory::testBlock.create(10);
// // //     
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     char* c1 = (char*)Iridescent::System::Memory::testBlock.requestChunk();
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     char* c2 = (char*)Iridescent::System::Memory::testBlock.requestChunk();
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     char* c3 = (char*)Iridescent::System::Memory::testBlock.requestChunk();
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     char* c4 = (char*)Iridescent::System::Memory::testBlock.requestChunk();
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     Iridescent::System::Memory::testBlock.returnChunk(c1);
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     char* c5 = (char*)Iridescent::System::Memory::testBlock.requestChunk();
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     
// // //     Iridescent::System::Memory::testBlock.returnChunk(c5);
// // //     Iridescent::System::Memory::testBlock.returnChunk(c3);
// // //     Iridescent::System::Memory::testBlock.returnChunk(c2);
// // //     Iridescent::System::Memory::testBlock.returnChunk(c4);
// // //     Iridescent::System::Memory::testBlock.printAll();
// // //     
// //     
// //     {
// //         Iridescent::System::Memory::testBlock.printAll();
// //         Iridescent::Core::Types::List<int> l;
// //         for ( auto i = 1; i <= 5; ++i )
// //         {
// //             //MyStruct* arr = (MyStruct*)Iridescent::System::Memory::Pool::get().allocate( sizeof(MyStruct) * i );
// //             //Iridescent::System::Memory::Pool::get().deallocate( arr );
// //             l.push_back( 256 );
// //             //std::cout << "Z" << std::endl;
// //             Iridescent::System::Memory::testBlock.printAll();
// //         }
// //         
// //         for ( auto&& e : l )
// //             std::cout << e << std::endl;
// //         std::cout << std::endl;
// //         
// //         Iridescent::System::Memory::testBlock.printAll();
// //     }
// //     
// //     Iridescent::System::Memory::testBlock.printAll();
// //     
// //     Iridescent::System::Memory::testBlock.destroy();
//     
//     /////////// memory pool test ////////////
//     
// //     std::cout << sizeof( Iridescent::System::Memory::Chunk<1> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<4> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<8> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<16> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<32> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<64> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<128> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<256> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<512> ) << std::endl
// //               << sizeof( Iridescent::System::Memory::Chunk<1024> ) << std::endl;
//     
// //     Iridescent::System::Memory::MemAddress head = nullptr;
// //     
// //     head = new Iridescent::System::Memory::Chunk4B;
//     
//     ////
//     
// //     Iridescent::System::Memory::Chunk4B* l1 = new Iridescent::System::Memory::Chunk4B;
// //     
// //     int* a = reinterpret_cast<int*>(l1);
// //     *a = 10;
// //     std::cout << "a: " << *a << std::endl;
// //     (*a)++;
// //     std::cout << "a: " << *a << std::endl;
// //     
// //     delete l1;
// //     
// //     short* b = reinterpret_cast<short*>(l1);
// //     *b = 255;
// //     std::cout << "b: " << *b << std::endl;
// //     (*b)++;
// //     std::cout << "b: " << *b << std::endl;
//     
//     ///
//     
// //     int* a =  new int;
// //     *a = 34;
// //     std::cout << *a << std::endl;
// //     delete a;
// //     *a = 213;
// //     std::cout << *a << std::endl;
//     
//     //std::cout << "l1: " << l1 << std::endl;
//     
//     //delete l1;
//     
// //     auto i = static_cast<Iridescent::System::Memory::Chunk4B*>( head );
// //     
// //     while ( i != nullptr )
// //     {
// //         auto t = i;
// //         i = i->next;
// //         delete t;
// //     }
//     
//     ////////////
//     
//     
// //     Iridescent::System::Memory::Block<16> block;
// //     auto s = block.create( 10 );
// // //     block.printAll();
// // //     std::cout << "Blocks: " << block.getTotalChunkCount() << std::endl;
// // //     block.resize(6);
// // //     std::cout << "Blocks: " << block.getTotalChunkCount() << std::endl;
// // //     block.printAll();
// //     //std::cout << "s: " << s << std::endl;// ", head(): " << ( block.head() != nullptr ) << std::endl;
// //     
// //     std::cout << "Free: " << block.getFreeChunkCount() << ", Used: " << block.getUsedChunkCount() << std::endl;
// //     
// //     int* i = block.requestChunk<int>();
// //     *i = 4;
// //     std::cout << "i: " << *i << std::endl;
// //     
// //     std::cout << "Free: " << block.getFreeChunkCount() << ", Used: " << block.getUsedChunkCount() << std::endl;
// //     
// //     struct MyStruct
// //     {
// //         int a;
// //         char b;
// //         double c;
// //     };
// //     
// //     MyStruct* sp = block.requestChunk<MyStruct>();
// //     sp->a = 123;
// //     sp->b = 'x';
// //     sp->c = 45613.354;
// //     
// //     std::cout << sizeof(MyStruct) << ", " << sizeof( Iridescent::System::Memory::Chunk16B ) << std::endl;
// //     
// //     std::cout << "sp: (" << sp->a << "," << sp->b << "," << sp->c << ")" << std::endl;
// //     
// //     std::cout << "Free: " << block.getFreeChunkCount() << ", Used: " << block.getUsedChunkCount() << std::endl;
// //     
// //     block.returnChunk( sp );
// //     
// //     std::cout << "Free: " << block.getFreeChunkCount() << ", Used: " << block.getUsedChunkCount() << std::endl;
// //     
// //     std::cout << "i: " << *i << std::endl;
// //     
// //     block.returnChunk( i );
// //     
// //     std::cout << "Free: " << block.getFreeChunkCount() << ", Used: " << block.getUsedChunkCount() << std::endl;
// //     
// //     block.destroy();
//     
//     //////////////
//     
// //     Iridescent::System::Memory::Pool pool;
// //     pool.create();
// //     
// //     int* i2 = (int*) pool.allocate( sizeof(int) );
// //     if ( i2 == nullptr )
// //         std::cout << "ASDSAD" << std::endl;
// //     *i2 = 912;
// //     std::cout << *i2 << std::endl;
// //     
// //     double* d = (double*)pool.allocate( sizeof(double) );
// //     *d = 303.14;
// //     std::cout << *d << std::endl;
// //     
// //     char* c = (char*)pool.allocate( sizeof(char) );
// //     *c = 'K';
// //     std::cout << *c << std::endl;
// //     
// //     struct MyStruct
// //     {
// //         int a;
// //         float b;
// //         std::string s;
// //     };
// //     
// //     MyStruct* ms = (MyStruct*)pool.allocate( sizeof(MyStruct) );
// //     ms->a = 505;
// //     ms->b = 3.142;
// //     ms->s = "Hello, World!";
// //     std::cout << "(" << ms->a << "," << ms->b << "," << ms->s << ")" << std::endl;
// //     int j = 456;
// //     std::cout << "j: " << j << std::endl;
// //     pool.deallocate( ms );
// //     pool.deallocate( c );
// //     pool.deallocate( d );
// //     pool.deallocate( i2 );
// //     
// //     pool.destroy();
