#include <iostream>
#include "FileCacheManager.h"
#include "mySerialServer.h"
int main() {
    mySerialServer lash;
    lash.open(6000, nullptr);
    lash.close();
    std::cout << "i got closed";
};