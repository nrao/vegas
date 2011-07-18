#ifndef ROACH_INTERFACE_H
#define ROACH_INTERFACE_H

// STL
#include <string>
#include <vector>
// Local
#include "Message.h"
// YGOR
//#include <tcpclient.h>


typedef std::string      Arg;
typedef std::vector<Arg> Args;

class Message;
class TcpClient;

class RoachInterface
{
public:
    RoachInterface(const char *addr, short port);
    ~RoachInterface();

    bool send_message(const Message &msg);
    bool send_message(char type, Arg name, int nargs = 0, ...); 
    Message recv_message();

private:
    //TCPClient m_tcp;
};

#endif//ROACH_INTERFACE_H
