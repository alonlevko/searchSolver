//
// Created by alon on 1/10/19.
//

#ifndef SEARCHSOLVER_PATH_H
#define SEARCHSOLVER_PATH_H

#include <vector>
#include <list>
#include "state.h"
template <class T>
class path {
private:
    std::vector<node<T>*> nodes;
public:
    path(std::vector<node<T>*> ns) {
        nodes = ns;
    }
    path(std::list<node<T>*> ns) {
        typedef typename std::list<node<T>*>::iterator a;
        for(a it = ns.begin(); it != ns.end(); ++it) {
            nodes.push_back(*it);
        }
    }
    int myWeight() {
        int weight = 0;
        typedef typename std::vector<node<T>*>::iterator b;
        for (b iter = nodes.begin(); iter != nodes.end(); iter++ ) {
            if(*iter != nullptr) {
                weight += (*(iter))->howHeavy();
            }
        }
        return weight;
    }

    std::string pathWaze() {
        std::string str;
        str+='{';
        str+=((*(nodes[0])).whichNeighbor(nodes[1]));
        int to = nodes.size() - 1;
        for(int i = 1; i < to; i++) {
            node<T>* next = nodes[i + 1];
            if(next == nullptr) {
                break;
            }
            str+=',';
            str+=' ';
            str+=nodes[i]->whichNeighbor(next);
        }
        str+='}';
        return str;
    }
};


#endif //SEARCHSOLVER_PATH_H
