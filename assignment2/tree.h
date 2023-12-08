// Storm van Rooden (s3520129) & Jonathan Hosea (s3712826)

#include <fstream>
#include "node.h"

#ifndef TREE
#define TREE

class Tree{

public:

    Tree(){
        root = nullptr;
    }

    void destroy(); // een functie om de boom te verwijderen en geheugen vrij te maken.
                    // zet root = nullptr

    Node* getRoot(){
        return root;
    }

    void setRoot(Node* root_){
        root = root_;
    }

    bool dot(const std::string & filename); // een functie om de boom op te slaan naar file, in DOT notatie
                                            // Verwacht een correcte boom.

private:
    void destroyRec(Node* n); // recursief onderdeel van destroy.

    void dotRec(std::ofstream & file, Node* n, size_t root); // recursieve onderdeel van dot.

    Node* root;
    size_t dotTeller;

};
#endif