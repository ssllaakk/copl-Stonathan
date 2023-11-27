#include "tree.h"

void Tree::destroy(){
    destroyRec(root);
    root = nullptr;
}

void Tree::destroyRec(Node* n){
    if(n == nullptr){ return; }
    destroyRec(n->getLeftChild());
    destroyRec(n->getRightChild());
    delete n;
}