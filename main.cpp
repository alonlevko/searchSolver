#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
#include "myClientHandler.h"
int main() {
    mySerialServer lash;
    myClientHandler test;
    lash.open(6594, &test);
    sleep(800);
    lash.close();
    std::cout << "i got closed";
};