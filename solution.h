#ifndef SEARCHSOLVER_SOLUTION_H
#define SEARCHSOLVER_SOLUTION_H
#include <string>
class solution {
private:
    std::string representation;
public:
    solution(std::string str) {
        representation = str;
    }
    std::string represent() {return representation;}
};
#endif //SEARCHSOLVER_SOLUTION_H
