//
// Created by alon on 1/9/19.
//

#ifndef SEARCHSOLVER_STRINGREVERSER_H
#define SEARCHSOLVER_STRINGREVERSER_H

#include "Solver.h"
#include <string>
class StringReverser: public solver<std::string,std::string> {
public:
    solver* clone() {
        return this;
    }
    std::string solve(std::string str) {
        /*
        std::string reverse;
        for(std::string::iterator it = str.end(); it != str.begin(); it--) {
            if(*it == '\\') {
                break;
            }
            reverse += *it;
        }
         */
        return "problem solved";
    }
};


#endif //SEARCHSOLVER_STRINGREVERSER_H
