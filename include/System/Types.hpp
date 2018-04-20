#ifndef SYSTEM_TYPES_HPP
#define SYSTEM_TYPES_HPP

#include <cstdint>

namespace Iridescent
{

namespace System
{

namespace Types
{

// A generic memory address
using MemAddress = void *;

// size_t
using std::size_t;

// Integer types
using UInt8  = std::uint8_t;
using UInt16 = std::uint16_t;
using UInt32 = std::uint32_t;
using UInt64 = std::uint64_t;

using Int8   = std::int8_t;
using Int16  = std::int16_t;
using Int32  = std::int32_t;
using Int64  = std::int64_t;

// Graphics related types

template <class T>
struct Vector2
{
    T x, y;
};

using Vector2i = Vector2<Int16>;
using Vector2u = Vector2<UInt16>;
using Vector2f = Vector2<float>;

template <class T>
struct Vector3
{
    T x, y, z;
};

using Vector3i = Vector3<Int16>;
using Vector3u = Vector3<UInt16>;
using Vector3f = Vector3<float>;

} // End of namespace Types

} // End of namespace System

} // End of namespace Iridescent

#endif // SYSTEM_TYPES_HPP
