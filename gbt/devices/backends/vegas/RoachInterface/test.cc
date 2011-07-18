#include "RoachInterface.h"

#include <iostream>

using namespace std;

int main()
{
    RoachInterface ri("roach3", 7147);

    ri.send_message(MessageType::REQUEST, "help", 1, "help");
    Message m = ri.recv_message();

    return 0;
}
