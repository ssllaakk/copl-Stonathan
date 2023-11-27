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

    void setToken(int token_){
        token = token_;
    }
    
    int getToken(){
        return token;
    }
    
private:
    int token;
    Node* leftChild;
    Node* rightChild;
};

#endif