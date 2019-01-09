#include "FileCacheManager.h"
FileCacheManager::FileCacheManager() {
    ourFile.open(fileName, std::ios::out | std::ios::in);
    std::string line;
    std::string problem;
    std::string solution;
    std::string delimiter = "$";
    int n;
    std::ifstream in(fileName);
    if(in.is_open()) {
        while(getline(in, line)) {
            n = line.find(delimiter);
            problem = line.substr(0, n);
            line.erase(0, n + 1);
            solution = line;
            alreadySaved[problem] = solution;
            line.clear();
            problem.clear();
            solution.clear();
        }
    } else {
        return;
    }
} // load all problems and solutions
FileCacheManager::~FileCacheManager() {
    if(ourFile.is_open()) {
        for (std::map<std::string, std::string>::iterator it = alreadySaved.begin();
             it != alreadySaved.end(); it++) {
            ourFile << it->first << "$" << it->second << std::endl;
        }
        ourFile.close();
    } else {
        ourFile.open(fileName, std::fstream::in | std::fstream::out);
        if(ourFile.is_open()) {
            for (std::map<std::string, std::string>::iterator it = alreadySaved.begin();
                 it != alreadySaved.end(); it++) {
                ourFile << it->first << "$" << it->second << std::endl;
            }
        }
        ourFile.close();
    }
}// save to the file all of the things
bool FileCacheManager::isSaved(problem p) {
    for(std::map<std::string, std::string>::iterator it = alreadySaved.begin();
        it != alreadySaved.end(); it++) {
        if(it->first.compare(p.represent())) {
            return true;
        }
    }
    return false;
}
solution FileCacheManager::getSolution(problem p) {
    if(isSaved(p)) {
        return solution(alreadySaved[p.represent()]);
    } else {
        return solution("");
    }
}
int FileCacheManager::saveSolution(problem p, solution s) {
    alreadySaved[p.represent()] = s.represent();
}
