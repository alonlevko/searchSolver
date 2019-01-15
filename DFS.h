#ifndef SEARCHSOLVER_DFS_H
#define SEARCHSOLVER_DFS_H

#include "searcher.h"
#include <list>
#include <set>
template <class T>
class DFS : public searcher<T> {
public:
    path<T> search(searchable<T>* searchable1) {
        std::list<path<T>> pathes;
        std::vector<node<T>*> singleRouth;
        singleRouth.resize(searchable1->getNodeNum());
        std::set<node<T>*> eval;
        node<T>* start = searchable1->getInitialState();
        node<T>* end = searchable1->getGoalState();
        int routhIndex = 0;
        findPathUtil(pathes, eval, start, end, singleRouth, routhIndex);
        path<T>* min = &(pathes.front());
        typedef typename std::list<path<T>>::iterator a;
        for(a it = pathes.begin(); it != pathes.end(); it++) {
            int m = min->myWeight();
            int n = it->myWeight();
            if(n < m) {
                min = &(*it);
            }
        }
        return *min;
    }
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
    ~DFS() {
        typedef typename std::vector<searcher<T> *>::iterator temp;
        for (temp it = copies.begin(); it != copies.end(); it++) {
            delete (*it);
        }
    }
    searcher<T>* clone() {
        searcher<T>* s = new DFS();
        copies.push_back(s);
        return s;
    }
private:
    std::vector<searcher<T>*> copies;
    void findPathUtil(std::list<path<T>>& pathes, std::set<node<T>*>& eval, node<T>* source, node<T>* end,
                                  std::vector<node<T>*>& routh, int& routhIndex) {
        nodeNum++;
        eval.insert(source);
        std::vector<node<T>*> neigh = source->neighbors();
        routh[routhIndex] = source;
        routhIndex++;
        if(source == end) {
            path<T> p(routh);
            pathes.push_back(p);
            return;
        } else {
            typedef typename std::vector<node<T>*>::iterator lash;
            for(lash it = neigh.begin(); it!=neigh.end(); it++) {
                node<T>* n = *it;
                if(eval.find(n) == eval.end()) {// if n was not evaluated
                    findPathUtil(pathes, eval, n, end, routh, routhIndex);
                }
            }
        }
    }
    int nodeNum = 0;
};


#endif //SEARCHSOLVER_DFS_H
