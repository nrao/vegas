// Parent
#include "RoachInterface.h"
// Local
// YGOR
// STL
#include <cstdarg>


RoachInterface::RoachInterface(const char *addr, short port)
//:
    //m_tcp(addr, port)
{
    //m_tcp.connect();
}

RoachInterface::~RoachInterface()
{
    //m_tcp.close();
}

bool
RoachInterface::sendMessage(const KatcpMessage &msg)
{
    KatcpArg raw_msg = msg.serialize();
    size_t n = raw_msg.size();
    // size_t n = m_tcp.write(const_cast<char*>(raw_msg.c_str()),
    //                        raw_msg.size());
    return n == raw_msg.size();
}

bool
RoachInterface::sendMessage(char type, KatcpArg name, int nargs, ...)
{
    KatcpMessage m(type, name);
    va_list args;
    va_start(args, nargs);
    for(int i = 0; i < nargs; ++i)
    {
        m.add_arg(va_arg(args, char*));
    }
    va_end(args);
    return sendMessage(m);
}

KatcpMessage
RoachInterface::recvMessage()
{
    char buffer[100] = "!wordwrite ok 1";
    //m_tcp.read(buffer, 100);
    return KatcpMessage::parse(buffer);
}
