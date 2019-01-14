#ifndef SEARCHSOLVER_SEARCHSOLVER_H
#define SEARCHSOLVER_SEARCHSOLVER_H

#include <string>
#include <vector>
#include "Solver.h"
#include "searchable.h"
#include "searcher.h"
class searchSolver: public solver<std::string, std::string> {
public:
    std::string solve(std::string);
    searchSolver(searcher* searcher2) {
        searcher1 = searcher2;
    }
    ~searchSolver() {
        for(std::vector<solver*>::iterator it = vec.begin(); it != vec.end(); it++) {
            delete(*it);
        }
    }
    solver* clone() {
        solver* s = new searchSolver(searcher1->clone());
        vec.push_back(s);
        return s;
    }
private:
    std::vector<solver*> vec;
    searcher* searcher1;
};
#endif //SEARCHSOLVER_SEARCHSOLVER_H
