#ifndef SEARCHSOLVER_CACHEMANAGER_H
#define SEARCHSOLVER_CACHEMANAGER_H
#include "solution.h"
#include "problem.h"
#include <map>
class CacheManager {
private:
protected:std::map<std::string, std::string> alreadySaved;
public:
    virtual bool isSaved(problem p) = 0;
    virtual solution getSolution(problem p) = 0;
    virtual int saveSolution(problem p, solution s) = 0;
};
#endif //SEARCHSOLVER_CACHEMANAGER_H
