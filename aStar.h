#ifndef SEARCHSOLVER_ASTAR_H
#define SEARCHSOLVER_ASTAR_H


#include "searcher.h"
#include <queue>
#include <set>
#include <vector>
template <class T>
class aStar: public searcher<T> {
public:
    bool static compareA(node<T>* left, node<T>* right) {return *right < *left;}
    path<T> search(searchable<T>* searchable1) {
        std::priority_queue<node<T>*, std::vector<node<T>*>, decltype(&compareA)> open(compareA);
        std::set<node<T>*> inOpen;
        std::set<node<T>*> eval;
        std::vector<node<T>*> negihs;
        node<T>* strt = searchable1->getInitialState();
        strt->updateDistance(0);
        open.push(strt);
        inOpen.insert(strt);
        //std::map<node*, int> gscore;
        while(!open.empty()) {
            numNodes++;
            node<T>* n = open.top();
            inOpen.erase(n);
            open.pop();
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
            } else {
                negihs = n->neighbors();
                typedef typename std::vector<node<T>*>::iterator lush;
                for(lush it = negihs.begin(); it!=negihs.end(); it++) {
                    node<T>*s = *it;
                    s->updateDistance(n->howFar() + s->howHeavy());
                    if(eval.find(s) != eval.end()) {
                        continue;
                    } else {
                        int tentative = n->howFar() + s->howHeavy();
                        if(inOpen.find(s) == inOpen.end()) {
                            open.push(s);
                            inOpen.insert(s);
                        } else if (tentative >= s->howFar()) {
                            continue;
                        }
                        s->updateSource(n);
                        s->updateDistance(tentative);
                        s->setHurAirDis(s->howFar() + s->getHurAir());
                    }
                }
            }
        }
    }
    ~aStar(){
        typedef typename std::vector<searcher<T>*>::iterator temp;
        for(temp it = copies.begin(); it != copies.end(); it++) {
            delete(*it);
        }
    }
    int numberOfNodesEvaluated() {
        return numNodes;
    }
    searcher<T>* clone() {
        searcher<T>* s = new aStar<T>();
        copies.push_back(s);
        return s;
    }
private:
    std::vector<searcher<T>*> copies;
    int numNodes = 0;
};


#endif //SEARCHSOLVER_ASTAR_H
