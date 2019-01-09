#include "FileCacheManager.h"
FileCacheManager::FileCacheManager() {
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
    }
} // load all problems and solutions
FileCacheManager::~FileCacheManager() {
        std::ofstream out(fileName);
        for (std::map<std::string, std::string>::iterator it = alreadySaved.begin();
             it != alreadySaved.end(); it++) {
            out << it->first << "$" << it->second << std::endl;
        }
        out.close();
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
