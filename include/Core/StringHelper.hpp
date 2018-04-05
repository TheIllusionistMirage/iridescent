/*
 * String Processor
 *
 */

#ifndef STRING_HELPER_HPP
#define STRING_HELPER_HPP

#include <string>
#include <algorithm> 
#include <cctype>


// Start of Iridescent's namespace
namespace Iridescent
{

// Start of Core module's namespace
namespace Core
{

// Start of String submodule's namespace
namespace String
{
/* Check if given string consits of just whitespaces */
static inline bool isWhitespace( const std::string& str )
{
    return !std::any_of( str.begin(), str.end(), [](char c){ return isgraph(c); } );
}

/* Trim the given string from left end */    
static inline void ltrim( std::string& str )
{
    str.erase( str.begin(), std::find_if( str.begin(), str.end(), [](char c){ return isgraph(c); } ) );
}

/* Trim the given string from right end */
static inline void rtrim( std::string& str )
{
    str.erase( std::find_if( str.rbegin(), str.rend(), [](char c){ return isgraph(c); } ).base(), str.end() );
}

/* Trim the given string from both ends */
static inline void trim( std::string& str )
{
    ltrim( str );
    rtrim( str );
}

static inline void split( std::string& str, std::string& left, std::string& right, const char delim = ' ' )
{
    // TODO 'cause splitting implies a vector of strings
    // being returned and I'mma write my own memory pool
}

}
// End of String submodule's namespace

}
// End of Core module's namespace

}
// End of engine's namespace

#endif // STRING_HELPER_HPP
