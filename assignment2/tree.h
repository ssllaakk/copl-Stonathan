// Storm van Rooden (s3520129) & Jonathan Hosea (s3712826)

#include "node.h"

#ifndef TREE
#define TREE

class Tree{

public:

    void destroy(); // een functie om de boom te verwijderen en geheugen vrij te maken.
                    // zet root = nullptr

    Node* getRoot(){
        return root;
    }

private:
    void destroyRec(Node* n); // recursief onderdeel van destroy.

    Node* root;

};
#endif