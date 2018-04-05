#ifndef CORE_TYPES_HPP
#define CORE_TYPES_HPP

#include <string>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

#include "System/Types.hpp"
#include "System/Memory/Allocator.hpp"

namespace Iridescent
{

namespace Core
{

namespace Types
{

// Data structures

using String = std::basic_string<char, std::char_traits<char>, System::Memory::SimpleAllocator<char>>;

// Fixed size array
// NOTE: The STL container std::array<T,N> doesn't use heap memory.
template <typename T, System::Types::UInt64 N>
using Array = std::array<T, N>;

// Dynamic array
template <typename T>
using Vector = std::vector<T, System::Memory::SimpleAllocator<T>>;

// Doubly linked list
template <typename T>
using List = std::list<T, System::Memory::SimpleAllocator<T>>;

// Stack
template <typename T>
using Stack = std::stack<T>;

// Queue
template <typename T>
using Queue = std::queue<T>;

// Map
template <typename K, typename V>
using Map = std::map<K, V, std::less<K>, System::Memory::SimpleAllocator<std::pair<const K, V>>>;

//

} // End of namespace Types

} // End of namespace Core

} // End of namespace Iridescent

#endif // CORE_TYPES_HPP
