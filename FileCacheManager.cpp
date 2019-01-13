#include "FileCacheManager.h"
FileCacheManager::FileCacheManager() {
    std::string line;
    std::string wholeFile;
    std::string problem;
    std::string solution;
    std::string delimiter = "$";
    std::string end = "$$";
    int n, n1;
    std::ifstream in(fileName);
    if(in.is_open()) {
        // read all of the file into wholeFile
        char c;
        while ((c = in.get()) != EOF) {
            wholeFile += c;
        }
        while(!wholeFile.empty()) {
            n1 = wholeFile.find(end);
            line = wholeFile.substr(0, n1);
            wholeFile.erase(0, n1 + 2);
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
            out << it->first << "$" << it->second << "$$";
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
