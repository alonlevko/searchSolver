#ifndef SEARCHSOLVER_ASTAR_H
#define SEARCHSOLVER_ASTAR_H


#include "searcher.h"

class aStar: public searcher {
public:
    path search(searchable* searchable1);
    ~aStar(){};
    int numberOfNodesEvaluated() {
        return numNodes;
    }
    searcher* clone() {
        searcher* s = new aStar();
        copies.push_back(s);
        return s;
    }
private:
    int numNodes = 0;
};


#endif //SEARCHSOLVER_ASTAR_H
