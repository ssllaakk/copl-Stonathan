#include "parser.h"

void Parser::start(){
    ast.destroy();
    ast.setRoot(new Node());
    expr();
    if(nextToken.code != TokenCodes::EOF_){
        error();
    }
}

Node* Parser::expr(){
    //std::cout << " Enter <expr>" << std::endl;
    Node* n = new Node();

    if(nextToken.code == TokenCodes::VAR){
        n->setToken(TokenCodes::VAR);
        nextToken = lex.getToken();
        // n is VAR of @ met VAR als linker kind en expr_ als rechterkind
        return buildSubTree(n , expr_());
    }else if(nextToken.code == TokenCodes::LEFT_PAREN){
        nextToken = lex.getToken();
        // n is de expressie tussen haakjes
        n = expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            nextToken = lex.getToken();
            // n is (expr) of @ met expr als linker kind en expr_ als rechterkind
            return buildSubTree(n , expr_());
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::LAMBDA){
        n->setToken(LAMBDA);
        nextToken = lex.getToken();
        if(nextToken.code == TokenCodes::VAR){
            //n->setVAR()
            nextToken = lex.getToken();
            // lambda node aanmaken en kind eronder plakken     
            n->setLeftChild(buildSubTree(expr() , expr_()));
            return n;
        }else{
            error();
        }
    }else{
        error();
    }
    
    //std::cout << "Exit <expr>" << std::endl;
}

Node* Parser::expr_(){
    //std::cout << " Enter <expr_>" << std::endl;


    if(nextToken.code == TokenCodes::VAR){
        nextToken = lex.getToken();
        expr_();
    }else if(nextToken.code == TokenCodes::LEFT_PAREN){
        nextToken = lex.getToken();
        expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            nextToken = lex.getToken();
            expr_();
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::LAMBDA){
        nextToken = lex.getToken();
        if(nextToken.code == TokenCodes::VAR){
            expr();
            expr_();
        }else{
            error();
        }
    }

    return nullptr;

    //std::cout << "Exit <expr_>" << std::endl;
}

void Parser::parse(std::string expression){
    currentExpression = expression;
    lex.setExpression(expression);
    lex.getChar();
    nextToken = lex.getToken();
    start();
}

void Parser::error(){
    passed = false;
    std::cout << "Invalid Syntax at expression " << currentExpression << std::endl 
    << "Exiting Program" << std::endl;
    exit(1); // LET OP MEMORY OPRUIMEN
}

Node*
Parser::buildSubTree(Node* left, Node* right){
    if(right != nullptr){
        // bouw @ met twee kinderen,
        // waarvan expr links, expr_ rechter
        Node* atNode = new Node();
        atNode->setToken(AT_SIGN);
        atNode->setLeftChild(left);
        atNode->setRightChild(right);
        return atNode;
    }
    return left;
}
