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
bool FileCacheManager::isSaved(std::string p) {
    for(std::map<std::string, std::string>::iterator it = alreadySaved.begin();
        it != alreadySaved.end(); it++) {
        if(it->first.compare(p) == 0) {
            return true;
        }
    }
    return false;
}
std::string FileCacheManager::getSolution(std::string p) {
    if(isSaved(p)) {
        return alreadySaved[p];
    } else {
        return "";
    }
}
int FileCacheManager::saveSolution(std::string p, std::string s) {
    alreadySaved[p] = s;
}
