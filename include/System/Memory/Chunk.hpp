/////////////////////////////////////////////////////////////////
// Chunk                                                       //
/////////////////////////////////////////////////////////////////
// A Chunk object encapsulates a chunk of memory. The sizes of //
// chunks are not arbitrary but carefully chosen values to     //
// possibly serve all requirements.                            //
/////////////////////////////////////////////////////////////////

#ifndef MEMORY_CHUNK_HPP
#define MEMORY_CHUNK_HPP

#include "System/Types.hpp"

namespace Iridescent
{

namespace System
{

namespace Memory
{

//////////////////////////////////
// Legal chunk sizes (in bytes) //
//////////////////////////////////
static constexpr Types::UInt16 MEMORY_CHUNK_SIZES[] =
{
    1    ,
    4    ,
    8    ,
    16   ,
    32   ,
    64   ,
    128  ,
    256  ,
    512  ,
    1024
};


/////////////////////////////////////////
// No. of different memory chunk sizes //
/////////////////////////////////////////
static constexpr int CHUNK_SIZE_COUNT = sizeof(MEMORY_CHUNK_SIZES) / sizeof(Types::UInt16);


////////////////////////////////////////////////////////////////////////////
// Check wheter or not a chunk size is one of the ones the pool uses.
//
// NOTE: This method is used only internally, within the pool as external
// allocation requests can be of arbitrary sizes.
////////////////////////////////////////////////////////////////////////////
inline bool chunkSizeGood( const Types::UInt16 chunkSize )
{
    bool sizeGood = false;
    
    for ( int i = 0; i < CHUNK_SIZE_COUNT; ++i )
    {
        if ( MEMORY_CHUNK_SIZES[i] == chunkSize )
        {
            sizeGood = true;
            break;
        }
    }
    
    return sizeGood;
}


/////////////////////////////////////////////////////////////////////
// Chunk type is a 'blob' of memory at least 'S' bytes wide. The
// no. of bytes compsing a chunk is a compile time parameter.
// When it's stored in the free memory pool, it behaves a linked
// list element. When it's assigned to an object, it is cast to
// the desired type using reinterpret_cast.
//
// NOTE: The minimum sizes of a Chunk in a 32-bit system is 4 bytes
// and that on a 64-bit system is 8 bytes. This wastage is a tradeoff
// for the ease of use in the design. Also, in most cases of use, each
// object will atleast be 4 or more bytes.
/////////////////////////////////////////////////////////////////////
template <Types::UInt64 S>
union Chunk
{
    Chunk<S>* next;
    Types::UInt8 data[S];
};


/////////////////////
// Helpful aliases //
/////////////////////
using Chunk4B    = Chunk<4>;
using Chunk8B    = Chunk<8>;
using Chunk16B   = Chunk<16>;
using Chunk32B   = Chunk<32>;
using Chunk64B   = Chunk<64>;
using Chunk128B  = Chunk<128>;
using Chunk256B  = Chunk<256>;
using Chunk512B  = Chunk<512>;
using Chunk1024B = Chunk<1024>;
// using Chunk2048B = Chunk<2048>;
// using Chunk4096B = Chunk<4096>;
// using Chunk8192B = Chunk<8192>;
// using Chunk16384B = Chunk<16384>;

} // End of Memory namespace

} // End of System namespace

} // End of Iridescent

#endif // MEMORY_CHUNK_HPP
