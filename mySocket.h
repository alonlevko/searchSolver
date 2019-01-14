#ifndef SEARCHSOLVER_SOCKET_H
#define SEARCHSOLVER_SOCKET_H
#include <string>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
namespace server_side {
    class mySocket {
    private:
        int socketID;
    public:
        mySocket(int id) {
            socketID = id;
        }
        bool writeOut(std::string str) {
            int n = write(socketID, str.c_str(), str.size());
            return n > 0;
        }
        bool readIn(std::string* str) {
            char buffer[BUFFER_SIZE];
            ::bzero(buffer, BUFFER_SIZE);
            int n = read(socketID, buffer, BUFFER_SIZE - 1);
            buffer[BUFFER_SIZE - 1] = '\0';
            str->clear();
            str->append(buffer);
            return n > 0;
        }
        void close() {
            ::close(socketID);
        }
    };
}


#endif //SEARCHSOLVER_SOCKET_H
