#ifndef SEARCHSOLVER_FILECACHEMANAGER_H
#define SEARCHSOLVER_FILECACHEMANAGER_H
#include "CacheManager.h"
#include <string>
#include <iostream>
#include <fstream>
class FileCacheManager: public CacheManager {
    std::string fileName = "problemSolutionCache.txt";
public:
    FileCacheManager(); // load all problems and solutions
    ~FileCacheManager();// save to the file all of the things
    bool isSaved(std::string p);
    std::string getSolution(std::string p);
    int saveSolution(std::string p, std::string s);
};


#endif //SEARCHSOLVER_FILECACHEMANAGER_H
