#include "BestFirstSearch.h"
#include "set"
bool compare(node* left, node* right) {return *right < *left;}
path BestFirstSearch::search(searchable* searchable1) {
    //auto cmp = [](node* left, node* right) {return *left < *right;};
    std::priority_queue<node*, std::vector<node*>, decltype(&compare)> open(compare);
    std::set<node*> inOpen;
    inOpen.insert(searchable1->getInitialState());
    std::set<node*> eval;
    std::vector<node*> neighbors;
    node* n = searchable1->getInitialState();
    n->updateDistance(0);
    open.push(n);
    while(!open.empty()) {
        nodeNum++;
        n = open.top();
        open.pop();
        inOpen.erase(inOpen.find(n));
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
        }
        neighbors = n->neighbors();
        for(std::vector<node*>::iterator it = neighbors.begin(); it != neighbors.end() ; it++) {
            node* s = *it;
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
                        node* k = open.top();
                        open.pop();
                        open.push(k);
                    }
                }
            }
        }
    }

}
