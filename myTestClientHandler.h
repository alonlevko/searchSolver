//
// Created by alon on 1/8/19.
//

#ifndef SEARCHSOLVER_MYTESTCLIENTHANDLER_H
#define SEARCHSOLVER_MYTESTCLIENTHANDLER_H
#include "socket.h"
#include "ClientHandler.h"
#include "Solver.h"
using namespace server_side;
class myTestClientHandler: public ClientHandler {
private:
    solver* solve;
public:
    int handleClient(socket in, socket out) {
        return 0;
    }
};


#endif //SEARCHSOLVER_MYTESTCLIENTHANDLER_H