#ifndef ROACH_INTERFACE_H
#define ROACH_INTERFACE_H

// STL
#include <string>
#include <vector>
// Local
#include "KatcpMessage.h"
// YGOR
//#include "tcpclient.h"


class TcpClient;

class RoachInterface
{
public:
    RoachInterface(const char *addr, short port);
    ~RoachInterface();

    bool sendMessage(const KatcpMessage &msg);
    bool sendMessage(char type, KatcpArg name, int nargs = 0, ...); 
    KatcpMessage recvMessage();

private:
    //TCPClient m_tcp;
};

#endif//ROACH_INTERFACE_H
