#ifndef MESSAGE_HPP
#define MESSAGE_HPP

// Start of Iridescent's namespace
namespace Iridescent
{

// Start of System module's namespace
namespace System
{

template< typename... Args>
class Message
{
    
public:
    
    // Construction & destruction
    Message();
    virtual ~Message();

public:
    
    // Message Interface API
    
    void create( Args... params );
    
    void destroy();
    
private:
    
    // Message internals
        
};

}
// End of System module's namespace

}
// End of Iridescent's namespace

#endif // MESSAGE_HPP
