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
RoachInterface::send_message(const Message &msg)
{
    std::string raw_msg = msg.serialize();
    size_t n = 0;//m_tcp.write(const_cast<char*>(raw_msg.c_str()), raw_msg.size());
    return n == raw_msg.size();
}

bool
RoachInterface::send_message(char type, Arg name, int nargs, ...)
{
    Message m(type, name);
    va_list args;
    va_start(args, nargs);
    for(int i = 0; i < nargs; ++i)
    {
        m.add_arg(va_arg(args, char*));
    }
    va_end(args);
    return send_message(m);
}

Message
RoachInterface::recv_message()
{
    char buffer[100];
    //m_tcp.read(buffer, 100);
    return Message::parse(buffer);
}
