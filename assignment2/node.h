#include "token.h"

#ifndef NODE
#define NODE

class Node{

public:

    Node(){
        leftChild = nullptr;
        rightChild = nullptr;
    }
    
    void setLeftChild(Node* leftChild_){
        leftChild = leftChild_;
    }

    void setRightChild(Node* rightChild_){
        rightChild = rightChild_;
    }

    Node* getLeftChild(){
        return leftChild;
    }

    Node* getRightChild(){
        return rightChild;
    }

    void setTokenCode(TokenCodes nwCode){
        token.code = nwCode;
    }

    void setTokenVar(std::string nwVar){
        token.var = nwVar;   
    }
    
    TokenCodes getTokenCode(){
        return token.code;
    }

    std::string getTokenVar(){
        return token.var;
    }
    
private:
    Token token;
    Node* leftChild;
    Node* rightChild;
};

#endif