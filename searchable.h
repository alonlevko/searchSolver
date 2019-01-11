#ifndef SEARCHSOLVER_SEARCHABLE_H
#define SEARCHSOLVER_SEARCHABLE_H

#include "state.h"
#include <list>
class searchable {
public:
    virtual node* getInitialState() = 0;
    virtual node* getGoalState() = 0;
    virtual std::vector<node*> getSucssesors(node* n) = 0;
};
#endif //SEARCHSOLVER_SEARCHABLE_H
