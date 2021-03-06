//
// Created by alon on 1/8/19.
//

#ifndef SEARCHSOLVER_CLIENTHANDLER_H
#define SEARCHSOLVER_CLIENTHANDLER_H

#include "mySocket.h"
using namespace server_side;
class ClientHandler {
public:
    virtual ClientHandler* clone() = 0;
    virtual int handleClient(mySocket in, mySocket out) = 0;
    ~ClientHandler(){};
};
#endif //SEARCHSOLVER_CLIENTHANDLER_H
