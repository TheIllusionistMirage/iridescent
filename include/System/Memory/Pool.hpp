///////////////////////////////////////////////////////////////////////////
// MemoryPool                                                            //
///////////////////////////////////////////////////////////////////////////
// Pool is an encapsulation of a memory pool. It is a custom written
// memory manager for Iridescent instead of relying on the compiler
// supplied malloc/free (CRT) and new/delete (C++RT) to take advantages
// of certain memory usage footprints commonly found in game engines. The
// interface to this memory pool are the allocate/deallocate methods.
//
// TODO: Pool is a singleton.
// 
// Externally, the pool can be viewed as a BIG area of free memory.
// Whenever a client requests for some memory, the pool returns a chunk
// of memory of size at least as big as the requested one.
//
// Internally, the pool consists of multiple blocks of memory, each of
// which are made up of fixed sized chunks. For more details about the
// Block and Chunk objects, take a look at Block.hpp and Chunk.hpp.
// 
// ISSUES:
// All allocations and deallocations must occur after the call to create()
// and before the call the destroy() (unless you're looking for UB)
///////////////////////////////////////////////////////////////////////////

#ifndef MEMORY_POOL_HPP
#define MEMORY_POOL_HPP

#include <map>

#include "System/Types.hpp"
#include "System/Log.hpp"
#include "Chunk.hpp"
#include "Block.hpp"

namespace Iridescent
{

namespace System
{

namespace Memory
{

///////////////////////////////////////////////////////////////////////////
// Pool class implements a memory pool in terms of memory blocks.
///////////////////////////////////////////////////////////////////////////
class Pool
{

public:
    
    static Pool& get();
    
public:
    
    ///////////////////////////////////////////////////////////////////////////
    // Default constructor
    ///////////////////////////////////////////////////////////////////////////
    Pool();
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Destructor
    ///////////////////////////////////////////////////////////////////////////
    ~Pool();
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Create the memory pool
    ///////////////////////////////////////////////////////////////////////////
    bool create();
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Destroy the memory pool
    ///////////////////////////////////////////////////////////////////////////
    // All memory blocks (and hence chunks) are released back to the OS.
    ///////////////////////////////////////////////////////////////////////////
    void destroy();
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Main allocation/deallocation API
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    // Returns a pointer to a memory buffer at least 'size' bytes wide
    ///////////////////////////////////////////////////////////////////////////
    Types::MemAddress allocate( const Types::UInt64 size )
    {
        Types::MemAddress address = nullptr;
        Types::Int16 block = 4;
        
        // Pick the best possible block to use
        
        if ( size <= 4 )
        {
            // Use block-4
            address = m_block4B.requestChunk();
            block = 4;
        }
        
        else if ( size > 4 && size <= 8 )
        {
            // Use block-8
            address = m_block8B.requestChunk();
            block = 8;
        }
        
        else if ( size > 8 && size <= 16 )
        {
            // Use block-16
            address = m_block16B.requestChunk();
            block = 16;
        }
        
        else if ( size > 16 && size <= 32 )
        {
            // Use block-32
            address = m_block32B.requestChunk();
            block = 32;
        }
        
        else if ( size > 32 && size <= 64 )
        {
            // Use block-64
            address = m_block64B.requestChunk();
            block = 64;
        }
        
        else if ( size > 64 && size <= 128 )
        {
            // Use block-128
            address = m_block128B.requestChunk();
            block = 128;
        }
        
        else if ( size > 128 && size <= 256 )
        {
            // Use block-256
            address = m_block256B.requestChunk();
            block = 256;
        }
        
        else if ( size > 256 && size <= 512 )
        {
            // Use block-512
            address = m_block512B.requestChunk();
            block = 512;
        }
        
        else if ( size > 512 && size <= 1024 )
        {
            // Use block-1024
            address = m_block1024B.requestChunk();
            block = 1024;
        }
        
        else
        {
            LOG(Log::Level::Error) << "Unable to find suitable memory block to allocate \'" << size << "\' bytes." << std::endl;
            //std::cout << "Unable to find suitable memory block to allocate \'" << size << "\' bytes." << std::endl;
        }
        
        if ( address != nullptr )
        {
            // Map the chunk under use to it's correct block
            m_activeChunkMap.insert( { address, block } );
            LOG(Log::Level::Debug) << "New chunk assigned by pool: " << address << ", Block: " << block << std::endl;
            //std::cout << "New chunk assigned by pool: " << address << ", Block: " << block << std::endl;
        }
        
        return address;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Deallocates the assigned memory buffer and adds it back to the memory
    // pool.
    ///////////////////////////////////////////////////////////////////////////
    void deallocate( Types::MemAddress chunk );
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Get a pointer to a specified block.
    ///////////////////////////////////////////////////////////////////////////
    template <Types::Int16 S>
    Block<S>* getBlock()
    {
//         switch ( S )
//         {
//             case 4:     return &m_block4B;
// //             case 8:     return &m_block8B;
// //             case 16:    return &m_block16B;
// //             case 32:    return &m_block32B;
// //             case 64:    return &m_block64B;
// //             case 128:   return &m_block128B;
// //             case 256:   return &m_block256B;
// //             case 512:   return &m_block512B;
// //             case 1024:  return &m_block1024B;
//             default:    return nullptr;
//         }
        return &m_block1024B;
    }
    
private:
    
    // Memory blocks that build up the pool
    Block4B    m_block4B;
    Block8B    m_block8B;
    Block16B   m_block16B;
    Block32B   m_block32B;
    Block64B   m_block64B;
    Block128B  m_block128B;
    Block256B  m_block256B;
    Block512B  m_block512B;
    Block1024B m_block1024B;
    
    // The default no. of chunks per block
    const std::map<Types::Int16, Types::Int64> m_chunksPerBlock = 
    {
        { 4, 100000 },
        { 8, 100000 },
        { 16, 100000 },
        { 32, 100000 },
        { 64, 100000 },
        { 128, 10000 },
        { 256, 10000 },
        { 512, 1000 },
        { 1024, 100 }
    };
    //Types::Map<Types::Int16, Types::Int64> m_chunksPerBlock;
    
    // Currently assigned chunks (used for returning a deallocated chunk to it's currect block)
    std::map<Types::MemAddress, Types::Int16> m_activeChunkMap;
    //Types::Map<Types::MemAddress, Types::Int16> m_activeChunkMap;
};

//static Pool MemoryPool;

static Block4B testBlock;

} // End of namespace Memory

} // End of namespace System

} // End of namespace Iridescent

#endif // MEMORY_POOL_HPP
