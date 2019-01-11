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
std::string searchSolver::solve(std::string str) {
    // the input needs to be a search matrix
    std::vector<std::vector<int>> matrix;
    std::istringstream sstrm(str);
    std::string line; // each line is a row
    std::string number;
    std::vector<int> row;
    while(std::getline(sstrm, line)) {
        if(str.find_first_not_of(' ') == std::string::npos) {
            break;
        }
        std::istringstream sstrm2(line);
        std::cout << line << std::endl;
        while(std::getline(sstrm2, number, ',')) {
                std::cout << number << std::endl;
                row.push_back(stoi(number));
                number.clear();
        }
        matrix.push_back(row);
        row.clear();
        line.clear();
    }
    searchable* searchable1 = new matrixGraph(matrix);
    searcher* searcher1 = new BestFirstSearch();
    path p = searcher1->search(searchable1);
    std::cout << p.pathWaze();
    return p.pathWaze();
}

