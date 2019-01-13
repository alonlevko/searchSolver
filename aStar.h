#ifndef SEARCHSOLVER_ASTAR_H
#define SEARCHSOLVER_ASTAR_H


#include "searcher.h"

class aStar: public searcher {
    path search(searchable* searchable1);
    ~aStar(){};
};


#endif //SEARCHSOLVER_ASTAR_H
