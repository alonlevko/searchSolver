//
// Created by alon on 1/8/19.
//

#ifndef SEARCHSOLVER_MYTESTCLIENTHANDLER_H
#define SEARCHSOLVER_MYTESTCLIENTHANDLER_H
#include "mySocket.h"
#include "ClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
using namespace server_side;
class myTestClientHandler: public ClientHandler {
private:
    FileCacheManager* manager;
    solver<std::string, std::string>* solve;
public:
    myTestClientHandler() {
        manager = new FileCacheManager();
        solve = new StringReverser();
    }
    ~myTestClientHandler() {
        delete(manager);
        delete(solve);
    }
    int handleClient(mySocket in, mySocket out) {
        std::string input;
        if(in.readIn(&input)) {
            if(manager->isSaved(input)) {
                out.writeOut(manager->getSolution(input));
            } else {
                std::string s = solve->solve(input);
                std::cout << s << std::endl;
                out.writeOut(s);
                manager->saveSolution(input, s);
            }
        }
    }
};


#endif //SEARCHSOLVER_MYTESTCLIENTHANDLER_H
