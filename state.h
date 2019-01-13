#ifndef SEARCHSOLVER_STATE_H
#define SEARCHSOLVER_STATE_H

#include <vector>
#include <string>
class node {
public:
    bool operator <(const node& other) {
        // a negative number is equal to infinity
        if(this->distance < 0) {
            return false;
        }
        if(other.distance < 0) {
            return true;
        }
        return (this->distance < other.distance);
    }
    bool weightSmaller(const node& other) {
        return (this->weight < other.weight);
    }
    std::vector<node*> neighbors() {
        std::vector<node*> vec;
        if(top != nullptr) {
            vec.push_back(top);
        }
        if(down != nullptr) {
            vec.push_back(down);
        }
        if(left != nullptr) {
            vec.push_back(left);
        }
        if(right != nullptr) {
            vec.push_back(right);
        }
        return vec;
    }
    void updateDistance(int x) {
        distance = x;
    }
    int howFar() {
        return this->distance;
    }
    int howHeavy(){
        return weight;
    }
    node(int w, int d, node* t, node* d2, node* l, node* r) {
        weight = w;
        distance = d;
        top = t;
        down = d2;
        left = l;
        right = r;
    }
    node(int w, int d) {
        weight = w;
        distance = d;
        top = nullptr;
        down = nullptr;
        left = nullptr;
        right = nullptr;
    }

    void setTop(node* t) {
        top = t;
    }
    void setDown(node* t) {
        down = t;
    }
    void setLeft(node* t) {
        left = t;
    }
    void setRight(node* t) {
        right = t;
    }

    bool isNeighbor(node* n) {
        if (this->top == n || this->right == n || this->down == n || this->left == n) {
            return true;
        }
        else {
            return false;
        }
    }

    std::string whichNeighbor(node* n) {
        if (this->top == n) {
            return "top";
        }
        if (this->down == n) {
            return "down";
        }
        if (this->left == n) {
            return "left";
        }
        if (this->right == n) {
            return "right";
        }
        else {
            return "false";
        }
    }
    void updateSource(node* s) {
        cameFrom = s;
    }
    node* source() {
        return cameFrom;
    }
    void setHurAirDis(int d) {
        airDist = d;
    }
    int getHurAir() {
        return airDist;
    }
private:
    node* cameFrom = nullptr;
    node* top;
    node* down;
    node* left;
    node* right;
    int weight;
    int distance;
    int airDist;
};


#endif //SEARCHSOLVER_STATE_H
