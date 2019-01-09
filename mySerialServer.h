//
// Created by alon on 1/8/19.
//

#ifndef SEARCHSOLVER_MYSERIALSERVER_H
#define SEARCHSOLVER_MYSERIALSERVER_H

#include <thread>
#include "mySocket.h"
#include "Server.h"
using namespace server_side;
class mySerialServer: public server {
private:
    std::thread* runner;
    bool stopper;
public:
    mySerialServer() {return;}
    ~mySerialServer() {return;}
    int open(int port, ClientHandler* handler);
    int close();
};


#endif //SEARCHSOLVER_MYSERIALSERVER_H
