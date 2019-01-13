//
// Created by alon on 1/10/19.
//

#ifndef SEARCHSOLVER_MYCLIENTHANDLER_H
#define SEARCHSOLVER_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "searchSolver.h"
#include <string>
#include "CacheManager.h"
#include "FileCacheManager.h"
class myClientHandler: public ClientHandler {
    int handleClient(mySocket in, mySocket out) {
        CacheManager* c = new FileCacheManager();
        solver<std::string, std::string>* solver1 = new searchSolver();
        std::string str;
        std::string temp;
        while(temp.find("end") == std::string::npos) {
            if(in.readIn(&temp)) {
                str += temp;
            } else {
                break;
            }
        }
        int pos = str.find("end");
        str.erase(pos, str.size());
        if(c->isSaved(str)) {
            out.writeOut(c->getSolution(str));
            return 1;
        }
        std::string answer = solver1->solve(str);
        out.writeOut(answer);
        c->saveSolution(str, answer);
        delete c;
        delete solver1;
        return 1;
    }
};


#endif //SEARCHSOLVER_MYCLIENTHANDLER_H
