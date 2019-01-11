#ifndef SEARCHSOLVER_SEARCHSOLVER_H
#define SEARCHSOLVER_SEARCHSOLVER_H

#include <string>
#include "Solver.h"
class searchSolver: public solver<std::string, std::string> {
    std::string solve(std::string);
};
#endif //SEARCHSOLVER_SEARCHSOLVER_H
