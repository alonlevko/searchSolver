#ifndef SEARCHSOLVER_DFS_H
#define SEARCHSOLVER_DFS_H

#include "searcher.h"
#include <list>
#include <set>
class DFS : public searcher {
public:
    path search(searchable* searchable1);
    int numberOfNodesEvaluated() {
        return nodeNum;
    }
    ~DFS(){};
    searcher* clone() {
        searcher* s = new DFS();
        copies.push_back(s);
        return s;
    }
private:
    void findPathUtil(std::list<path>& pathes, std::set<node*>& eval, node* source, node* end,
                                  std::vector<node*>& routh, int& routhIndex);
    int nodeNum = 0;
};


#endif //SEARCHSOLVER_DFS_H
