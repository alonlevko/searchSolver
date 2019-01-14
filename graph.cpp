//
// Created by alon on 1/10/19.
//

#include "graph.h"
#include <math.h>
matrixGraph::matrixGraph(std::vector<std::vector<int>>& matrix, int (&s)[2], int (&e)[2]) {
    start[0] = s[0];
    start[1] = s[1];
    end[0] = e[0];
    end[1] = e[1];
    matrixNodes.resize(matrix.size());
    for(int i = 0; i < matrix.size(); ++i) {
        matrixNodes[i].resize(matrix[i].size());
        for(int j = 0; j < matrix[i].size(); ++j) {
            matrixNodes[i][j] = new node(matrix[i][j], -1);
        }
    }
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            int distance = (int)sqrt(pow(end[0] - i, 2) + pow(end[1] - j, 2));
            matrixNodes[i][j]->setHurAirDis(distance);
            if(i-1 > 0 && matrixNodes[i-1][j]->howHeavy() > 0) {
                matrixNodes[i][j]->setTop(matrixNodes[i-1][j]);
            }
            if(i + 1 < matrix.size() && matrixNodes[i+1][j]->howHeavy() > 0) {
                matrixNodes[i][j]->setDown(matrixNodes[i + 1][j]);
            }
            if(j - 1 > 0 && matrixNodes[i][j - 1]->howHeavy() > 0) {
                matrixNodes[i][j]->setLeft(matrixNodes[i][j - 1]);
            }
            if (j + 1 < matrix[i].size() && matrixNodes[i][j + 1]->howHeavy() > 0) {
                matrixNodes[i][j]->setRight(matrixNodes[i][j + 1]);
            }
        }
    }
}

matrixGraph::~matrixGraph() {
    for(int i = 0; i < matrixNodes.size(); ++i) {
        for (int j = 0; j < matrixNodes[i].size(); ++j) {
            delete matrixNodes[i][j];
        }
    }
}