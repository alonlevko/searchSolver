#ifndef SEARCHSOLVER_SEARCHER_H
#define SEARCHSOLVER_SEARCHER_H
#include "path.h"
#include "searchable.h"
class searcher {
public:
    virtual path search(searchable* searchable1) = 0;
    virtual ~searcher(){};
};
#endif //SEARCHSOLVER_SEARCHER_H
