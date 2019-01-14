//
// Created by alon on 1/13/19.
//

#include "aStar.h"
#include <queue>
#include <set>
#include <vector>
bool compareA(node* left, node* right) {return *right < *left;}
path aStar::search(searchable* searchable1) {
    // distance will be fscore
    std::priority_queue<node*, std::vector<node*>, decltype(&compareA)> open(compareA);
    std::set<node*> inOpen;
    std::set<node*> eval;
    std::vector<node*> negihs;
    node* strt = searchable1->getInitialState();
    strt->updateDistance(0);
    open.push(strt);
    inOpen.insert(strt);
    //std::map<node*, int> gscore;
    while(!open.empty()) {
        numNodes++;
        node* n = open.top();
        inOpen.erase(n);
        open.pop();
        eval.insert(n);
        if(n == searchable1->getGoalState()) {
            node* i = searchable1->getGoalState();
            std::list<node*> vec;
            while(i != nullptr) {
                vec.push_front(i);
                i = i->source();
            }
            path p(vec);
            return p;
        } else {
            negihs = n->neighbors();
            for(std::vector<node*>::iterator it = negihs.begin(); it!=negihs.end(); it++) {
                node*s = *it;
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