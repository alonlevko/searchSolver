#ifndef SEARCHSOLVER_PROBLEM_H
#define SEARCHSOLVER_PROBLEM_H

#include <string>
class problem{
private:
    std::string representation;
public:
    problem(std::string str) {
        representation = str;
    }
    std::string represent() {return representation;};
};
#endif //SEARCHSOLVER_PROBLEM_H
