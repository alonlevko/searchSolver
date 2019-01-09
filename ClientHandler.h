//
// Created by alon on 1/8/19.
//

#ifndef SEARCHSOLVER_CLIENTHANDLER_H
#define SEARCHSOLVER_CLIENTHANDLER_H

#include "socket.h"
using namespace server_side;
class ClientHandler {
    virtual int handleClient(socket in, socket out) = 0;
};
#endif //SEARCHSOLVER_CLIENTHANDLER_H
