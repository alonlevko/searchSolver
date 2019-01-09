#include <iostream>
#include "FileCacheManager.h"
int main() {
    FileCacheManager manager;
    problem p("lish lash4");
    solution s("ahhh5");
    problem p1("lish lash6");
    solution s1("ahhh7");
    manager.saveSolution(p, s);
    manager.saveSolution(p1, s1);
}