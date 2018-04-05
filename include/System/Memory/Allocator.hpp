///////////////////////////////////////////////////////////////////////////
// Allocator
///////////////////////////////////////////////////////////////////////////

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include "System/Log.hpp"
#include "System/Memory/Pool.hpp"

namespace Iridescent
{

namespace System
{

namespace Memory
{

// Allocator interface
template <typename T>
class IAllocator
{

// public:
//     
    using size_type = std::size_t;
//     using difference_type = std::ptrdiff_t;
    using pointer = T*;
//     using const_pointer = const T*;
//     using reference = T&;
//     using const_reference = const T&;
//     using value_type = T;
//     
//     template <typename U>
//     using other = IAllocator<U>;

public:
    
    virtual pointer allocate( size_type n ) = 0;
    virtual void deallocate(pointer p, size_type n) = 0;

private:

    
};

///////////////////////////////////////////////////////////////////////////
// A simple allocator
///////////////////////////////////////////////////////////////////////////
template <typename T>
class SimpleAllocator : public IAllocator<T>
{
    
public:
    
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;
    
    template <typename U>
    using other = IAllocator<U>;
    
public:
    
    //SimpleAllocator(){}
    //~SimpleAllocator(){}

    pointer allocate( size_type n )
    {
        //std::cout << "allocate(): " << n << std::endl;
        return reinterpret_cast<pointer>( Memory::Pool::get().allocate( n * sizeof(value_type) ) );
        //return reinterpret_cast<pointer>( Memory::testBlock.requestChunk() );
//         return reinterpret_cast<pointer>( new char[n * sizeof(value_type)] );
    }
    
    void deallocate( pointer p, size_type n)
    {
        //std::cout << "deallocate(): " << std::endl;
        Memory::Pool::get().deallocate( p );
        //Memory::testBlock.returnChunk(p);
//         delete[] reinterpret_cast<char*>(p);
    }

};


// Default STL allocator interface
// template <typename T>
// class Allocator
// {
// 
// public:
//     
//     using size_type = std::size_t;
//     using difference_type = std::ptrdiff_t;
//     using pointer = T*;
//     using const_pointer = const T*;
//     using reference = T&;
//     using const_reference = const T&;
//     using value_type = T;
//     
//     template <typename U>
//     using other = Allocator<U>;
//     
// public:
//     
//     Allocator() noexcept;
//     Allocator( const Allocator& allocator ) noexcept;
//     template <typename U>
//     Allocator( const Allocator<U>& allocator ) noexcept;
//     ~Allocator();
//     
//     pointer address( reference x ) const noexcept;
//     const pointer address( const_reference x ) const noexcept;
//     
//     // pointer allocate( size_type n, Allocator<void>::const_pointer hint = 0 );
//     pointer allocate( size_type n, Allocator<T>::const_pointer hint = 0 );
//     void deallocate(pointer p, size_type n);
//     
//     size_type max_size() const noexcept;
//     
//     template <typename U, typename... Args>
//     void construct(U* p, Args&&... args);
//     
//     template <typename U>
//     void destroy(U* p);
//     
// private:
//     
//     
//     
// };

} // End of namespace Memory

} // End of namespace System

} // End of namespace Iridescent

#endif // ALLOCATOR_HPP
