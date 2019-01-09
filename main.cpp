#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
int main() {
    mySerialServer lash;
    lash.open(6000, nullptr);
    sleep(30);
    //lash.close();
    std::cout << "i got closed";
};