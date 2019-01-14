#ifndef SEARCHSOLVER_SEARCHER_H
#define SEARCHSOLVER_SEARCHER_H
#include "path.h"
#include "searchable.h"
#include <vector>
class searcher {
protected:
    std::vector<searcher*> copies;
public:
    virtual path search(searchable* searchable1) = 0;
    virtual ~searcher() {
        for(std::vector<searcher*>::iterator it = copies.begin(); it != copies.end(); it++) {
            delete(*it);
        }
    }
    virtual int numberOfNodesEvaluated() = 0;
    virtual searcher* clone() = 0;
};
#endif //SEARCHSOLVER_SEARCHER_H
