#ifndef SEARCHSOLVER_SEARCHABLE_H
#define SEARCHSOLVER_SEARCHABLE_H

#include "state.h"
#include <list>
template <class T>
class searchable {
public:
    virtual node<T>* getInitialState() = 0;
    virtual node<T>* getGoalState() = 0;
    virtual std::vector<node<T>*> getSucssesors(node<T>* n) = 0;
    virtual ~searchable(){}
    virtual int getNodeNum() = 0;
};
#endif //SEARCHSOLVER_SEARCHABLE_H
