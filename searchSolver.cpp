#include "searchSolver.h"
#include <sstream>
#include <iostream>
#include <string>
#include "graph.h"
#include <vector>
#include "searcher.h"
#include "searchable.h"
#include "graph.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "BFS.h"
#include "aStar.h"
std::string searchSolver::solve(std::string str) {
    // the input needs to be a search matrix
    std::vector<std::vector<int>> matrix;
    std::istringstream sstrm(str);
    std::string line; // each line is a row
    std::string number;
    std::vector<int> row;
    int numbersInRow = 0;
    int rowsRead = 0;
    bool c = true;
    while(std::getline(sstrm, line)) {
        if(numbersInRow != 0 && rowsRead != 0 && numbersInRow == rowsRead) {
            break;
        }
        if(str.find_first_not_of(' ') == std::string::npos) {
            break;
        }
        std::istringstream sstrm2(line);
        std::cout << line << std::endl;
        while(std::getline(sstrm2, number, ',')) {
                std::cout << number << std::endl;
                if(c) {
                    numbersInRow++;
                }
                row.push_back(stoi(number));
                number.clear();
        }
        matrix.push_back(row);
        c = false;
        rowsRead++;
        row.clear();
        line.clear();
    }
    int start[2];
    int end[2];
    std::istringstream sstrm2(line);
    std::getline(sstrm2, number, ',');
    start[0] = stoi(number);
    number.clear();
    std::getline(sstrm2, number, ',');
    start[1] = stoi(number);
    line.clear();
    std::getline(sstrm, line);
    std::istringstream sstrm3(line);
    std::getline(sstrm3, number, ',');
    end[0] = stoi(number);
    number.clear();
    std::getline(sstrm3, number, ',');
    end[1] = stoi(number);
    searchable* searchable1 = new matrixGraph(matrix, start, end);
    searcher* searcher1 = new aStar();
    path p = searcher1->search(searchable1);
    std::string waze = p.pathWaze();
    delete searchable1;
    delete searcher1;
    return waze;
}

