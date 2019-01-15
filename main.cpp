#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
#include "myParallelServer.h"
#include "myClientHandler.h"
#include "BFS.h"
#include "DFS.h"
#include "aStar.h"
#include "BestFirstSearch.h"
namespace boot {
    class Main {
        int main(int argc, char **argv) {
            myParallelServer serv;
            FileCacheManager man;
            aStar<int> sear;
            searchSolver s(&sear);
            myClientHandler test(&man, &s);
            int port = atoi(argv[1]);
            serv.open(port, &test);
            serv.close();
        };
    }
}