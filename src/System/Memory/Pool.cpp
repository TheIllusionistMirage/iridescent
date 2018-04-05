#include <iostream>

#include "System/Memory/Pool.hpp"

namespace Iridescent
{

namespace System
{

namespace Memory
{

// Pool class implementation

Pool& Pool::get()
{
    static Pool m_instance;
    return m_instance;
}

Pool::Pool()
{
    
}

///////////////////////////////////////////////////////////////////////////

Pool::~Pool()
{
    
}

///////////////////////////////////////////////////////////////////////////

bool Pool::create()
{
    bool status = true;
    
    // Initialize the default chunks per block info
    // TODO: Read this value from the config file
    m_chunksPerBlock[4] = 100000;
    m_chunksPerBlock[8] = 100000;
    m_chunksPerBlock[16] = 100000;
    m_chunksPerBlock[32] = 100000;
    m_chunksPerBlock[64] = 100000;
    m_chunksPerBlock[128] = 10000;
    m_chunksPerBlock[256] = 10000;
    m_chunksPerBlock[512] = 1000;
    m_chunksPerBlock[1024] = 100;
    
    // Initialize the blocks one by one
    
    // Create the 4B chunk block
    bool b4 = m_block4B.create( m_chunksPerBlock[4] );
    
    // Create the 8B chunk block
    bool b8 = m_block8B.create( m_chunksPerBlock[8] );
    
    // Create the 16B chunk block
    bool b16 = m_block16B.create( m_chunksPerBlock[16] );
    
    // Create the 32B chunk block
    bool b32 = m_block32B.create( m_chunksPerBlock[32] );
    
    // Create the 64B chunk block
    bool b64 = m_block64B.create( m_chunksPerBlock[64] );
    
    // Create the 128B chunk block
    bool b128 = m_block128B.create( m_chunksPerBlock[128] );
    
    // Create the 256B chunk block
    bool b256 = m_block256B.create( m_chunksPerBlock[256] );
    
    // Create the 512B chunk block
    bool b512 = m_block512B.create( m_chunksPerBlock[512] );
    
    // Create the 1024B chunk block
    bool b1024 = m_block1024B.create( m_chunksPerBlock[1024] );
    
    status = b4 && b8 && b16 && b32 && b64 && b128 && b256 && b512 && b1024;
    
    LOG(Log::Level::Info) << "Created memory pool." << std::endl;
    
    return status;
}

///////////////////////////////////////////////////////////////////////////

void Pool::destroy()
{
    // Destroy the blocks one by one
    
    // Destroy the 4B chunk block
    m_block4B.destroy();
    
    // Destroy the 8B chunk block
    m_block8B.destroy();
    
    // Destroy the 16B chunk block
    m_block16B.destroy();
    
    // Destroy the 32B chunk block
    m_block32B.destroy();
    
    // Destroy the 64B chunk block
    m_block64B.destroy();
    
    // Destroy the 128B chunk block
    m_block128B.destroy();
    
    // Destroy the 256B chunk block
    m_block256B.destroy();
    
    // Destroy the 512B chunk block
    m_block512B.destroy();
    
    // Destroy the 1024B chunk block
    m_block1024B.destroy();
    
    LOG(Log::Level::Info) << "Destroyed memory pool" << std::endl;
}

///////////////////////////////////////////////////////////////////////////

void Pool::deallocate( Types::MemAddress chunk )
{
    auto it = m_activeChunkMap.find( chunk );
    
    if ( it != m_activeChunkMap.end() )
    {
        auto block = it->second;
        
        switch ( block )
        {
            case 4: m_block4B.returnChunk( chunk ); break;
            case 8: m_block8B.returnChunk( chunk ); break;
            case 16: m_block16B.returnChunk( chunk ); break;
            case 32: m_block32B.returnChunk( chunk ); break;
            case 64: m_block64B.returnChunk( chunk ); break;
            case 128: m_block128B.returnChunk( chunk ); break;
            case 256: m_block256B.returnChunk( chunk ); break;
            case 512: m_block512B.returnChunk( chunk ); break;
            case 1024: m_block1024B.returnChunk( chunk ); break;
        }
        
        LOG(Log::Level::Debug) << "Deallocated chunk: " << chunk << ", block: " << block << std::endl;
        //std::cout << "Deallocated chunk: " << chunk << ", block: " << block << std::endl;
        m_activeChunkMap.erase( it );
    }
    else
    {
        LOG(Log::Level::Error) << "deallocate(): FATAL ERROR!, Unrecognized chunk: " << chunk << std::endl;
        //std::cout << "deallocate(): FATAL ERROR!, Unrecognized chunk: " << chunk << std::endl;
    }
}
    
} // End of Memory namespace

} // End of System namespace

} // End of Iridescent namespace
