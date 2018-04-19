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
    
    pointer allocate( size_type n )
    {
        return reinterpret_cast<pointer>( Memory::Pool::get().allocate( n * sizeof(value_type) ) );
    }
    
    void deallocate( pointer p, size_type n)
    {
        Memory::Pool::get().deallocate( p );
    }

};

} // End of namespace Memory

} // End of namespace System

} // End of namespace Iridescent

#endif // ALLOCATOR_HPP
