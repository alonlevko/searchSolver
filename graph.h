//
// Created by alon on 1/10/19.
//

#ifndef SEARCHSOLVER_GRAPH_H
#define SEARCHSOLVER_GRAPH_H

#include "searchable.h"
#include <string>
#include <vector>
#include <set>
class matrixGraph: public searchable {
private:
    std::vector<std::vector<node*>> matrixNodes;
public:
    matrixGraph(std::vector<std::vector<int>>& matrix);
    node* getInitialState() {
        return matrixNodes[0][0];
    }
    node* getGoalState() {
        int n = matrixNodes.size();
        return matrixNodes[n-1][n-1];
    }
    std::vector<node*> getSucssesors(node* n) {
        return n->neighbors();
    }
};
#endif //SEARCHSOLVER_GRAPH_H
