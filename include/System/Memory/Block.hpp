///////////////////////////////////////////////////////////////////////////
// Block                                                                 //
///////////////////////////////////////////////////////////////////////////
// A memory block is a large block of memory, consisting of
// equisized memory chunks. A number of memory blocks together
// constitute the memory pool.
//
// Internally, a memory block is implemented as a singly linked
// list, where the elements of the list are memory chunks of equal
// size, i.e., a single memory block can only contain chunks of a
// particular size. This restriction eases the process of quickly
// serving a free chunk depending upon the client's size
// requirements.
//
// Initially the entire block is composed of a linked list of free
// chunks. Whenever a chunk request is made to the block, the front
// chunk is returned. Whenever a freed chunk is returned to the
// block, it is inserted to the front. Thus, both are constant time
// operations.
//
// For the details of the Chunk class, see Chunk.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef MEMORY_BLOCK_HPP
#define MEMORY_BLOCK_HPP

#include "System/Types.hpp"
#include "System/Log.hpp"
#include "Chunk.hpp"

namespace Iridescent
{

namespace System
{

namespace Memory
{
    
///////////////////////////////////////////////////////////////////////////
// Block type is a collection of equisized memory chunks.
// The size of the chunks that compose the block are a
// compile time parameter.
///////////////////////////////////////////////////////////////////////////
template <Types::UInt16 S>
class Block
{
    
public:
    
    ///////////////////////////////////////////////////////////////////////////
    // Default consructor
    ///////////////////////////////////////////////////////////////////////////
    // The constructor initializes the Block object to a default, invalid
    // state.
    // NOTE: The chunk size of the block is supplied as a template parameter
    // and cannot be altered again. Not much flexibility is needed in this
    // case as the chunk sizes supported by the pool are decided before hand
    // and will not undergo a rapid change.
    ///////////////////////////////////////////////////////////////////////////
    Block() :
     m_chunkSize(S)  ,
     m_totalChunks(0),
     m_freeChunks(0) ,
     m_usedChunks(0) ,
     m_head(nullptr) ,
     m_tail(nullptr)
    {
        // Check if the passed chunk is permissble
        if ( !chunkSizeGood( m_chunkSize ) )
        {
            m_chunkSize = 0;
        }
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Destructor
    ///////////////////////////////////////////////////////////////////////////
    // The destructor destroys the memory held by the block (if already not
    // deallocated) and then sets the object to a default, invalid state.
    ///////////////////////////////////////////////////////////////////////////    
    ~Block()
    {
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Create a memory block 
    ///////////////////////////////////////////////////////////////////////////
    // Create a memory block with specified chunk size & count.
    // NOTE: The specified chunk size must be one of the
    // predefined ones.
    ///////////////////////////////////////////////////////////////////////////
    bool create( const Types::UInt64 chunkCount )
    {
        bool success = true;
        
        if ( !chunkSizeGood( m_chunkSize ) )
        {
            LOG(Log::Level::Error) << "Cannot create memory block, invalid"
                                   << "chunk size: " << m_chunkSize
                                   << ". Use one of the predefined ones "
                                   << "(Consult Chunk.hpp for more details)."
                                   << std::endl;
            success = false;
        }
        
        else
        {
            LOG(Log::Level::Debug) << "Creating a memory block with chunk size: "
                                   << m_chunkSize << std::endl;
            
            if ( !resize( chunkCount ) )
            {
                LOG(Log::Level::Error) << "Unable to create a memory block with chunk size: "
                                       << m_chunkSize << std::endl;
                success = false;
            }
            
            else
            {
                LOG(Log::Level::Debug) << "Created a memory block with chunk size: "
                                      << m_chunkSize << std::endl;
                
                m_totalChunks = chunkCount;
                m_freeChunks = m_totalChunks;
                m_usedChunks = m_totalChunks - m_freeChunks;
            }
        }
        
        return success;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Destroy the memory block
    ///////////////////////////////////////////////////////////////////////////
    // Destroys the memory held by the block and then sets the object to a
    // default, invalid state.
    // NOTE: After calling destroy(), the memory held by the block object is
    // released back to the OS but if the block is again created by invoking
    // create(), then the chunk size remains the same (because it remains a
    // compile time parameter).
    ///////////////////////////////////////////////////////////////////////////
    void destroy()
    {
        clear();
        
        m_totalChunks = 0;
        m_freeChunks = 0;
        m_usedChunks = 0;
        m_head = nullptr;
        m_tail = nullptr;
        
        LOG(Log::Level::Debug) << "Destroyed memory block with chunk size: " << m_chunkSize << std::endl;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Expand the block by adding more chunks when the block is full or
    // nearly full.
    // 
    // TODO: Determine an optimal condition to decide when this expansion
    // must happen.
    // Currently, the block size is doubled every time it reaches
    // the usage limit.
    ///////////////////////////////////////////////////////////////////////////
    bool expandBlock()
    {
        // TODO
        // stub...
        //return true;
        return resize( m_totalChunks * 2 );
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Returns the no. of chunks currently in the block.
    ///////////////////////////////////////////////////////////////////////////
    inline Types::UInt64 getTotalChunkCount() const
    {
        return m_totalChunks;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Returns the no. of free chunks currently in the block.
    ///////////////////////////////////////////////////////////////////////////
    inline Types::UInt64 getFreeChunkCount() const
    {
        return m_freeChunks;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Returns the no. of chunks in the block currently in use.
    ///////////////////////////////////////////////////////////////////////////
    inline Types::UInt64 getUsedChunkCount() const
    {
        return m_usedChunks;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Returns a free chunk from the block.
    ///////////////////////////////////////////////////////////////////////////
    Types::MemAddress requestChunk()
    {
        Chunk<S>* chunk = nullptr;
        
        // TODO: Expand and then return
        if ( m_freeChunks == 0 )
        {
            // return nullptr;
            if ( !expandBlock() )
                return nullptr;
        }
        
        // Update block info
        chunk = m_head;
        m_head = m_head->next;
        m_freeChunks--;
        m_usedChunks++;
        
        return chunk;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Reclaims an used chunk and adds it back to the block for future
    // allocation.
    ///////////////////////////////////////////////////////////////////////////
    void returnChunk( Types::MemAddress chunk )
    {
        // Error checking
        if ( chunk == nullptr || m_freeChunks == m_totalChunks )
            return;
        
        // Recast it back to the Chunk type and add it to the block
        auto i = reinterpret_cast<Chunk<S>*>( chunk );
        i->next = m_head;
        m_head = i;
        
        // Update block info
        m_freeChunks++;
        m_usedChunks--;
    }
    
    //// DEBUG
    
    void printAll()
    {
        int j = 0;
        for ( auto i = m_head; i != nullptr; i = i->next )
        {
            std::cout << i << std::endl;
        }
        std::cout << std::endl;
    }
    

private:
    
    ///////////////////////////////////////////////////////////////////////////
    // Resize the block chunk to `size`
    ///////////////////////////////////////////////////////////////////////////
    bool resize( const Types::UInt64 size )
    {
        bool success = true;
        
        // If new size == old size, do nothing.
        
        if ( m_totalChunks == size )
            return success;
        
        // If new size > old size, just insert the
        // remaining at the front of the list.
        else if ( m_totalChunks < size )
        {
            auto oldSize = m_totalChunks;
            insert( size - m_totalChunks );
            LOG(Log::Level::Debug) << "Resized Block with chunk size: "
                                   << m_chunkSize << ". Old size: "
                                   << oldSize << ", New size: "
                                   << size << std::endl;
        }
        
        // If new size < old size, just remove 'old size'
        // no. of chunks from the front of the list.
        else
        {
            auto oldSize = m_totalChunks;
            remove( m_totalChunks - size );
            LOG(Log::Level::Debug) << "Resized Block with chunk size: "
                                   << m_chunkSize << ". Old size: "
                                   << oldSize << ", New size: "
                                   << size << std::endl;
        }
        
        //printAll();
        
        return success;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    //                         Linked list helpers                           //
    ///////////////////////////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////////////////////////
    // Insert the given no. of chunks to the list. These new chunks are added
    // to the front of the list.
    ///////////////////////////////////////////////////////////////////////////
    void insert( const Types::UInt64 count )
    {
        Types::UInt64 j = 0;
        
        while ( j < count )
        {
            // First insertion
            if ( m_head == nullptr )
            {
                auto chunk = new Chunk<S>;
                chunk->next = nullptr;
                m_head = chunk;
            }
            
            else
            {
                auto chunk = new Chunk<S>;
                chunk->next = m_head;
                m_head = chunk;
            }
            
            ++j;
            ++m_totalChunks;
        }
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Remove given no. of chunks from the list. These chunks are removed from
    // the front of the list.
    ///////////////////////////////////////////////////////////////////////////
    void remove( const Types::UInt64 count )
    {
        auto i = m_head;
        Types::UInt64 j = 0;
        
        while ( j < count && i != nullptr )
        {
            auto t = i;
            i = i->next;
            delete t;
            
            ++j;
            --m_totalChunks;
        }
        
        if ( i != nullptr )
            m_head = i;
        else
            m_head = nullptr;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Clear the linked list.
    ///////////////////////////////////////////////////////////////////////////
    void clear()
    {
        auto i = m_head;
        
        while ( i != nullptr )
        {
            auto t = i;
            i = i->next;
            
            //free( t->data );
            delete t;
        }
    }
    
private:
    
    // The chunk size of each memory area within the block
    Types::Int16 m_chunkSize;
    
    // Denotes the total no. of chunks currently present in the block
    Types::UInt64 m_totalChunks;
    
    // Denotes the total no. of free chunks available in the block
    // (These chunks may be allocated)
    Types::UInt64 m_freeChunks;
    
    // Denotes the total no. of chunks in the block currently in use
    // (These chunks are already allocated. They have to be deallocated
    // before becoming free again)
    Types::UInt64 m_usedChunks;
    
    // Pointer to the next free chunk in the block
    Chunk<S>* m_head;
    
    // Pointer to the last free chunk in the block
    Chunk<S>* m_tail;
    
};


/////////////////////
// Helpful aliases //
/////////////////////
using Block4B    = Block<4>;
using Block8B    = Block<8>;
using Block16B   = Block<16>;
using Block32B   = Block<32>;
using Block64B   = Block<64>;
using Block128B  = Block<128>;
using Block256B  = Block<256>;
using Block512B  = Block<512>;
using Block1024B = Block<1024>;

} // End of Memory namespace

} // End of System namespace

} // End of Iridescent namespace

#endif // MEMORY_BLOCK_HPP
