#ifndef SEARCHSOLVER_BESTFIRSTSEARCH_H
#define SEARCHSOLVER_BESTFIRSTSEARCH_H
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "graph.h"
#include "state.h"
#include "searcher.h"
class BestFirstSearch: public searcher  {
    path search(searchable* searchable1);
};


#endif //SEARCHSOLVER_BESTFIRSTSEARCH_H
