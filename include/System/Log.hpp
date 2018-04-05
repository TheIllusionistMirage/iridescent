#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

// #ifndef __FILENAME__
//     #define __FILENAME__ __FILE__
// #endif

// Fetch the filename which invokes the logger
#define __FILENAME__ std::string( __FILE__ ).substr( std::string( __FILE__ ).find("iridescent") )

#define LOG(level) \
if (level > Iridescent::System::Log::get().getLevel()) ; \
else Iridescent::System::Log::get().getStream() << Iridescent::System::Log::levelStr( level ) << "[" << __FILENAME__ << ":" << std::dec << __LINE__ << "] "

namespace Iridescent
{

namespace System
{

class Log
{

public:
    
    enum class Level
    {
        Error,
        Info,
        Debug,
    };
    
    static inline const std::string levelStr(Level lvl)
    {
        std::string levelMap[] = { "[ ERROR ]", "[ INFO  ]", "[ DEBUG ]" };

        auto index = static_cast<int>(lvl);

        if ( index <= static_cast<int>( Level::Debug ) )
            return levelMap[index];

        return "";
    }
    
public:
    void setLogStream(std::ostream& stream);
    Log& setLevel(Level level);
    Level getLevel();

    std::ostream& getStream();
    static Log& get();
private:
    Level m_logLevel;
    std::ostream* m_logStream;
};


// Courtesy of http://wordaligned.org/articles/cpp-streambufs#toctee-streams
class TeeBuf : public std::streambuf
{
    public:
        // Construct a streambuf which tees output to both input
        // streambufs.
        TeeBuf(std::streambuf* sb1, std::streambuf* sb2);
    private:
        // This tee buffer has no buffer. So every character "overflows"
        // and can be put directly into the teed buffers.
        virtual int overflow(int c);
        // Sync both teed buffers.
        virtual int sync();
    private:
        std::streambuf* m_sb1;
        std::streambuf* m_sb2;
};

// Can be used to log into two ostream objects (like cout plus file)
class TeeStream : public std::ostream
{
    public:
        // Construct an ostream which tees output to the supplied
        // ostreams.
        TeeStream(std::ostream& o1, std::ostream& o2);
    private:
        TeeBuf m_tbuf;
};

} // End of namespace System

} // End of namespace Iridescent

#endif // LOG_HPP
