#ifndef SEARCHSOLVER_BESTFIRSTSEARCH_H
#define SEARCHSOLVER_BESTFIRSTSEARCH_H
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "graph.h"
#include "state.h"
#include "searcher.h"
template <class T>
class BestFirstSearch: public searcher<T>  {
public:
    bool static compare(node<T>* left, node<T>* right) {return *right < *left;}
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
    path<T> search(searchable<T>* searchable1) {
        //auto cmp = [](node* left, node* right) {return *left < *right;};
        std::priority_queue<node<T>*, std::vector<node<T>*>, decltype(&compare)> open(compare);
        std::set<node<T>*> inOpen;
        inOpen.insert(searchable1->getInitialState());
        std::set<node<T>*> eval;
        std::vector<node<T>*> neighbors;
        node<T>* n = searchable1->getInitialState();
        n->updateDistance(0);
        open.push(n);
        while(!open.empty()) {
            nodeNum++;
            n = open.top();
            open.pop();
            inOpen.erase(inOpen.find(n));
            eval.insert(n);
            if(n == searchable1->getGoalState()) {
                node<T>* i = searchable1->getGoalState();
                std::list<node<T>*> vec;
                while(i != nullptr) {
                    vec.push_front(i);
                    i = i->source();
                }
                path<T> p(vec);
                return p;
            }
            neighbors = n->neighbors();
            typedef typename std::vector<node<T>*>::iterator i;
            for(i it = neighbors.begin(); it != neighbors.end() ; it++) {
                node<T>* s = *it;
                s->updateDistance(n->howFar() + s->howHeavy());
                if(eval.find(s) == eval.end() && inOpen.find(s) == inOpen.end()) {
                    s->updateSource(n);
                    s->updateDistance(n->howFar() + s->howHeavy());
                    open.push(s);
                    inOpen.insert(s);
                } else {
                    if(*(s) < *(open.top())) {
                        if(inOpen.find(s) == inOpen.end()) {
                            //s->updateSource(n);
                            open.push(s);
                            inOpen.insert(s);
                        } else {
                            //s->updateDistance(n->howFar() + s->howHeavy());
                            node<T>* k = open.top();
                            open.pop();
                            open.push(k);
                        }
                    }
                }
            }
        }

    }
    ~BestFirstSearch(){
        typedef typename std::vector<searcher<T> *>::iterator temp;
        for (temp it = copies.begin(); it != copies.end(); it++) {
            delete (*it);
        }
    }
    searcher<T>* clone() {
        searcher<T>* s = new BestFirstSearch();
        copies.push_back(s);
        return s;
    }
private:
    std::vector<searcher<T>*> copies;
    int nodeNum = 0;
};


#endif //SEARCHSOLVER_BESTFIRSTSEARCH_H
