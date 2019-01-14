#ifndef SEARCHSOLVER_SEARCHER_H
#define SEARCHSOLVER_SEARCHER_H
#include "path.h"
#include "searchable.h"
#include <vector>
template <class T>
class searcher {
protected:
    //std::vector<searcher<T>*> copies;
public:
    virtual path<T> search(searchable<T>* searchable1) = 0;
    virtual ~searcher() {
        /*
        typedef typename std::vector<searcher<T>*>::iterator temp;
        for(temp it = copies.begin(); it != copies.end(); it++) {
            delete(*it);
        }
         */
    }
    virtual int numberOfNodesEvaluated() = 0;
    virtual searcher<T>* clone() = 0;
};
#endif //SEARCHSOLVER_SEARCHER_H
