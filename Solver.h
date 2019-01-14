#ifndef SEARCHSOLVER_SOLVER_H
#define SEARCHSOLVER_SOLVER_H
template <class Problem,class Solution>
class solver {
public:
    virtual Solution solve(Problem) = 0;
    virtual solver* clone() = 0;
    virtual ~solver(){};
};
#endif //SEARCHSOLVER_SOLVER_H
