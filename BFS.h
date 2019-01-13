#ifndef SEARCHSOLVER_BFS_H
#define SEARCHSOLVER_BFS_H

#include "searcher.h"
#include "searchable.h"
#include "path.h"
#include "state.h"
#include <queue>
#include <set>

class BFS : public searcher{
public:
    path search(searchable* searchable1);
    ~BFS(){}

};


#endif //SEARCHSOLVER_BFS_H
