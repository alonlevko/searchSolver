#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
#include "myClientHandler.h"
int main() {
    mySerialServer lash;
    myClientHandler test;
    lash.open(7416, &test);
    sleep(600);
    //lash.close();
    std::cout << "i got closed";
};