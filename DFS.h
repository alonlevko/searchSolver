#ifndef SEARCHSOLVER_DFS_H
#define SEARCHSOLVER_DFS_H

#include "searcher.h"
#include <list>
#include <set>
class DFS : public searcher {
public:
    path search(searchable* searchable1);
    ~DFS(){};
private:
    void findPathUtil(std::list<path>& pathes, std::set<node*>& eval, node* source, node* end,
                                  std::vector<node*>& routh, int& routhIndex);
};


#endif //SEARCHSOLVER_DFS_H
