#ifndef SEARCHSOLVER_BFS_H
#define SEARCHSOLVER_BFS_H

#include "searcher.h"
#include "searchable.h"
#include "path.h"
#include "state.h"
#include <queue>
#include <set>

class BFS : public searcher{
private:
    int nodeNum = 0;
public:
    searcher* clone() {
        searcher* s = new BFS();
        copies.push_back(s);
        return s;
    }
    path search(searchable* searchable1);
    ~BFS(){}
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
};


#endif //SEARCHSOLVER_BFS_H
