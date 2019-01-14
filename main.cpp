#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
#include "myParallelServer.h"
#include "myClientHandler.h"
#include "BFS.h"
#include "DFS.h"
#include "aStar.h"
#include "BestFirstSearch.h"
int main() {
    myParallelServer lash;
    FileCacheManager man;
    BFS<int> bfd;
    searchSolver s(&bfd);
    myClientHandler test(&man, &s);
    lash.open(6513, &test);
    sleep(300);
    lash.close();
    std::cout << "i got closed";
};