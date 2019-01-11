//
// Created by alon on 1/10/19.
//

#ifndef SEARCHSOLVER_PATH_H
#define SEARCHSOLVER_PATH_H

#include <vector>
#include <list>
#include "state.h"
class path {
private:
    std::vector<node*> nodes;
public:
    path(std::vector<node*> ns) {
        nodes = ns;
    }
    path(std::list<node*> ns) {
        for(std::list<node*>::iterator it = ns.begin(); it != ns.end(); ++it) {
            nodes.push_back(*it);
        }
    }
    int myWeight() {
        int weight = 0;
        for (std::vector<node*>::iterator iter = nodes.begin(); iter != nodes.end(); iter++ ) {
            weight += (*(iter))->howHeavy();
        }
        return weight;
    }

    std::string pathWaze() {
        std::string str;
        str+='{';
        str+=((*(nodes[0])).whichNeighbor(nodes[1]));
        for(int i = 1; i < nodes.size(); i++) {
            node* next = nodes[i + 1];
            str+=',';
            str+=' ';
            str+=nodes[i]->whichNeighbor(next);
        }
        str+='}';
        return str;
    }
};


#endif //SEARCHSOLVER_PATH_H
