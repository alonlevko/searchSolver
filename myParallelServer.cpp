#include "myParallelServer.h"
#define TIME_OUT_FIRST 20
#define TIME_OUT 1
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include "mySocket.h"
#include <thread>
void sendClient(server_side::mySocket in, server_side::mySocket out, ClientHandler* hand) {
    hand->handleClient(in, in);
    in.close();
    out.close();
}
void doWhatINeed2(bool* stop, int* sock,void* cli, socklen_t* clil, ClientHandler* handler1) {
    struct sockaddr cli1 = *((struct sockaddr*) cli);
    socklen_t clil1 = *clil;
    int sock1 = *sock;
    struct timeval tv;
    tv.tv_sec = TIME_OUT;
    tv.tv_usec = 0;
    bool optionSet = true;
    while(*(stop)) {
        int newsockfd = accept(sock1, &cli1, &clil1);
        if(newsockfd < 0) {
            std::cout << ("ERROR on accept") << std::endl;
            return;
        }
        server_side::mySocket in(newsockfd);
        std::thread t(sendClient, in, in, handler1->clone());
        t.detach();
        if(optionSet) {
            setsockopt(*sock, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv,
                       sizeof tv);
            optionSet = false;
        }
    }
    ::close(sock1);
}

int myParallelServer::open(int port, ClientHandler* handler) {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cout << ("ERROR opening socket") << std::endl;
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        std::cout << ("ERROR on binding") << std::endl ;
    struct timeval tv;
    tv.tv_sec = TIME_OUT_FIRST;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    listen(sockfd,200);
    clilen = sizeof(cli_addr);
    stopper = true;
    bool* a = &stopper;
    int* b = &sockfd;
    struct sockaddr_in* c = &cli_addr;
    socklen_t* d = &clilen;
    std::thread run(doWhatINeed2, a, b, c, d, handler);
    run.join();
}