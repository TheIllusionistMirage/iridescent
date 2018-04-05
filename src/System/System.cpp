#include <iostream>

#include "System/Log.hpp"
#include "System/System.hpp"

namespace Iridescent
{

namespace System
{

void Info::initSystemInfo()
{
    m_32bit = sizeof(void*) == 4 ? true : false;
    
    LOG(Iridescent::System::Log::Level::Info) << "Initialized system info." << std::endl;
}

}

}
