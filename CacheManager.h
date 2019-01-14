#ifndef SEARCHSOLVER_CACHEMANAGER_H
#define SEARCHSOLVER_CACHEMANAGER_H
#include "solution.h"
#include "problem.h"
#include <map>
#include <vector>
class CacheManager {
private:
protected:
    std::map<std::string, std::string> alreadySaved;
public:
    virtual bool isSaved(std::string p) = 0;
    virtual std::string getSolution(std::string p) = 0;
    virtual int saveSolution(std::string p, std::string s) = 0;
    virtual ~CacheManager(){};
};
#endif //SEARCHSOLVER_CACHEMANAGER_H
