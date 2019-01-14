#ifndef SEARCHSOLVER_BFS_H
#define SEARCHSOLVER_BFS_H

#include "searcher.h"
#include "searchable.h"
#include "path.h"
#include "state.h"
#include <queue>
#include <set>
template <class T>
class BFS : public searcher<T>{
private:
    int nodeNum = 0;
    std::vector<searcher<T>*> copies;
public:
    searcher<T>* clone() {
        searcher<T>* s = new BFS<T>();
        copies.push_back(s);
        return s;
    }
    path<T> search(searchable<T>* searchable1) {
        std::queue<node<T>*> open;
        std::set<node<T>*> eval;
        std::vector<node<T>*> negibors;
        open.push(searchable1->getInitialState());
        eval.insert(searchable1->getInitialState());
        while(!open.empty()) {
            nodeNum++;
            node<T>* n = open.front();
            open.pop();
            if(n==searchable1->getGoalState()) {
                node<T>* i = searchable1->getGoalState();
                std::list<node<T>*> vec;
                while(i != nullptr) {
                    vec.push_front(i);
                    i = i->source();
                }
                path<T> p(vec);
                return p;
            } else {
                negibors = n->neighbors();
                typedef typename std::vector<node<T>*>::iterator a;
                for(a it = negibors.begin(); it != negibors.end(); it++) {
                    node<T>* s = *it;
                    if(eval.find(s) != eval.end()) {
                        continue;
                    } else {
                        s->updateSource(n);
                        eval.insert(s);
                        open.push(s);
                    }
                }
                //eval.insert(n);
            }
        }
    }
    ~BFS(){
        typedef typename std::vector<searcher<T>*>::iterator temp;
        for(temp it = copies.begin(); it != copies.end(); it++) {
            delete(*it);
        }
    }
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
};


#endif //SEARCHSOLVER_BFS_H
