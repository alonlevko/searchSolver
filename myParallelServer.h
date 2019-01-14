//
// Created by alon on 1/13/19.
//

#ifndef SEARCHSOLVER_MYPARALLELSERVER_H
#define SEARCHSOLVER_MYPARALLELSERVER_H

#include "mySocket.h"
#include "Server.h"

using namespace server_side;
class myParallelServer : public server {
private:
    bool stopper;
public:
    int open(int port, ClientHandler* handler);
    int close() {
        stopper = false;
    }
};


#endif //SEARCHSOLVER_MYPARALLELSERVER_H
