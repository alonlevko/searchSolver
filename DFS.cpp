//
// Created by alon on 1/12/19.
//

#include "DFS.h"
path DFS::search(searchable* searchable1) {
    std::list<path> pathes;
    std::vector<node*> singleRouth;
    singleRouth.resize(searchable1->getNodeNum());
    std::set<node*> eval;
    node* start = searchable1->getInitialState();
    node* end = searchable1->getGoalState();
    int routhIndex = 0;
    findPathUtil(pathes, eval, start, end, singleRouth, routhIndex);
    path* min = &(pathes.front());
    for(std::list<path>::iterator it = pathes.begin(); it != pathes.end(); it++) {
        int m = min->myWeight();
        int n = it->myWeight();
        if(n < m) {
            min = &(*it);
        }
    }
    return *min;
}

void DFS::findPathUtil(std::list<path>& pathes, std::set<node*>& eval, node* source, node* end,
        std::vector<node*>& routh, int& routhIndex) {
        nodeNum++;
        eval.insert(source);
        std::vector<node*> neigh = source->neighbors();
        routh[routhIndex] = source;
        routhIndex++;
        if(source == end) {
            path p(routh);
            pathes.push_back(p);
            return;
        } else {
            for(std::vector<node*>::iterator it = neigh.begin(); it!=neigh.end(); it++) {
                node* n = *it;
                if(eval.find(n) == eval.end()) {// if n was not evaluated
                    findPathUtil(pathes, eval, n, end, routh, routhIndex);
                }
            }
        }
        //routhIndex--;
        //eval.erase(source);
}