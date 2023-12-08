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

bool Tree::dot(const std::string & filename){
    if(root == nullptr) return false;
    std::ofstream file(filename);
    dotTeller = 0;
    
    
    file << "digraph G {" << std::endl;
    file << "  " << std::to_string(dotTeller) << "[label=\"" 
         << root->getTokenString() << "\"]" << std::endl;
    dotTeller++;
    dotRec(file, root, 0);
    file << "}" << std::endl;

    file.close(); 
    return true;
}

void Tree::dotRec(std::ofstream & file, Node* n, size_t root){
    if(n == nullptr) return;
    size_t number = dotTeller;
    dotTeller++;
    file << "  " << std::to_string(number) << " [label=\"" << n->getTokenString() << "\"]" << std::endl;
    file << "  " << std::to_string(root) << " -> " << std::to_string(number) << std::endl;
   
    dotRec(file, n->getLeftChild(), number);
    dotRec(file, n->getRightChild(), number);
}