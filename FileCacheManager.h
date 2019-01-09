#ifndef SEARCHSOLVER_FILECACHEMANAGER_H
#define SEARCHSOLVER_FILECACHEMANAGER_H
#include "CacheManager.h"
#include <string>
#include <iostream>
#include <fstream>
class FileCacheManager: public CacheManager {
    std::string fileName = "problemSolutionCache.txt";
    std::fstream ourFile;
public:
    FileCacheManager(); // load all problems and solutions
    ~FileCacheManager();// save to the file all of the things
    bool isSaved(problem p);
    solution getSolution(problem p);
    int saveSolution(problem p, solution s);
};


#endif //SEARCHSOLVER_FILECACHEMANAGER_H
