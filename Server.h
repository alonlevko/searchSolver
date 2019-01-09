#ifndef SEARCHSOLVER_SERVER_H
#define SEARCHSOLVER_SERVER_H
#include "socket.h"
#include "ClientHandler.h"
using namespace server_side;
class server {
public:
    virtual int open(int port, ClientHandler* handler) = 0;
    virtual int close(int port) = 0;
};
#endif //SEARCHSOLVER_SERVER_H
