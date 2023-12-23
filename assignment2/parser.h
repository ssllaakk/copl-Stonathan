#include "lex.h"
#include "tree.h"

#ifndef PARSER
#define PARSER

// Parser for the Lambda Calculus language.
class Parser{

public:

    // a function to read a token and apply the language rules
    void parse(std::string expression);

    // getter for bool passed
    bool getPassed(){
        return passed;
    }

    void dot();
    
private:

    // functions

    // Calls function expr. When expr returns it will check if all tokens
    // have been handled, if not raise error.
    void start();

    // ⟨expr⟩ ::= ⟨lexpr⟩ ⟨expr'⟩
    Node* expr();

    // ⟨expr'⟩ ::= ⟨lexpr⟩ ⟨expr'⟩ | ε
    Node* expr_(Node* left);

    // ⟨lexpr⟩ ::= ⟨pexpr⟩ | '\' ⟨var⟩ ⟨lexpr⟩
    Node* lexpr();

    // ⟨pexpr⟩ ::= ⟨var⟩ | '(' ⟨expr⟩ ')'
    Node* pexpr();

    // 
    void error();

    // Builds a subtree with an @ if right is not a nullptr
    Node* buildSubTree(Node* left, Node* right);
    
    void updateToken();

    // variables
    Token nextToken;
    bool passed = true; // a variable that keeps track if the parser detected errors
                        // true if no errors, false if errors.

    Lex lex; // lexical analyser used by the parser

    std::string currentExpression;

    Tree ast; // abstract syntax tree


};

#endif