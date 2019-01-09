#include "mySerialServer.h"
#define TIME_OUT_SEC 20
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

int mySerialServer::open(int port, ClientHandler* handler) {
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
    tv.tv_sec = TIME_OUT_SEC;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    this->stopper = true;
    std::thread run([](bool* stop, int sock, void* cli, sockaddr_in* clil) {
    while(*(stop)) {
        int newsockfd = ::accept(sock,(struct sockaddr *) &cli, &clil);
        if(newsockfd == 0) {
            continue;
        }
        server_side::mySocket in(newsockfd);
        in.writeOut("i am your king");
        //server_side::mySocket out(newsockfd);
        //handler->handleClient(in, out);
        if (newsockfd < 0)
            std::cout << ("ERROR on accept") << std::endl;
        ::close(newsockfd);
        std::cout << " i closed a socket";
    }
    ::close(sock);
    });
}
int mySerialServer::close() {
    stopper = false;
}