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
    int start[2];
    int end[2];
public:
    matrixGraph(std::vector<std::vector<int>>& matrix, int (&s)[2], int (&e)[2]);
    ~matrixGraph();
    node* getInitialState() {
        return matrixNodes[start[0]][start[1]];
    }
    node* getGoalState() {
        int n = matrixNodes.size();
        return matrixNodes[end[0]][end[1]];
    }
    std::vector<node*> getSucssesors(node* n) {
        return n->neighbors();
    }
    int getNodeNum() {
        return matrixNodes.size() * matrixNodes[0].size();
    }
};
#endif //SEARCHSOLVER_GRAPH_H
