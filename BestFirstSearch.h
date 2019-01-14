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
public:
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
    path search(searchable* searchable1);
    ~BestFirstSearch(){return;}
    searcher* clone() {
        searcher* s = new BestFirstSearch();
        copies.push_back(s);
        return s;
    }
private:
    int nodeNum = 0;
};


#endif //SEARCHSOLVER_BESTFIRSTSEARCH_H
