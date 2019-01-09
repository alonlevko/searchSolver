#ifndef SEARCHSOLVER_SOCKET_H
#define SEARCHSOLVER_SOCKET_H
#include <string>
#include <unistd.h>
#define BUFFER_SIZE 256
namespace server_side {
    class socket {
    private:
        int socketID;
    public:
        socket(int id) {
            socketID = id;
        }
        bool writeOut(std::string str) {
            int n = write(socketID, str.c_str(), str.size());
            return n > 0;
        }
        bool readIn(std::string* str) {
            char buffer[BUFFER_SIZE];
            int n = read(socketID, buffer, BUFFER_SIZE);
            str->clear();
            str->append(buffer);
            return n > 0;
        }
    };
}


#endif //SEARCHSOLVER_SOCKET_H
