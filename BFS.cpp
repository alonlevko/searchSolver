//
// Created by alon on 1/12/19.
//

#include "BFS.h"
#include <vector>
path BFS::search(searchable* searchable1) {
    std::queue<node*> open;
    std::set<node*> eval;
    std::vector<node*> negibors;
    open.push(searchable1->getInitialState());
    eval.insert(searchable1->getInitialState());
    while(!open.empty()) {
        nodeNum++;
        node* n = open.front();
        open.pop();
        if(n==searchable1->getGoalState()) {
            node* i = searchable1->getGoalState();
            std::list<node*> vec;
            while(i != nullptr) {
                vec.push_front(i);
                i = i->source();
            }
            path p(vec);
            return p;
        } else {
            negibors = n->neighbors();
            for(std::vector<node*>::iterator it = negibors.begin(); it != negibors.end(); it++) {
                node* s = *it;
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