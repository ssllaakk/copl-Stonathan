#include "parser.h"

void Parser::start(){
    ast.destroy();
    ast.setRoot(expr());
    if(nextToken.code != TokenCodes::EOF_){
        error();
    }
}

Node* Parser::expr(){
    //std::cout << " Enter <expr> " << std::endl;
   
   lexpr();
   expr_();

    // std::cout << "Exit <expr>" << std::endl;
    return nullptr;
}

Node* Parser::expr_(){
    // std::cout << " Enter <expr_>" << std::endl;

    // Hoe bepaal je of je de empty string moet nemen?
    if(nextToken.code != TokenCodes::EOF_){
        lexpr();
        expr_();
    }

    //std::cout << "Exit <expr_>" << std::endl;
    return nullptr;
}

Node* Parser::lexpr(){
    // std::cout << " Enter <lexpr>" << std::endl;

    if(nextToken.code == TokenCodes::LAMBDA){
        nextToken = lex.getToken();
        if(nextToken.code == TokenCodes::VAR){
            /* TODO: Maak Lambda token aan */
            
            lexpr();
        }else{
            error();
        }
    }else{
        pexpr();
    }
    
    return nullptr;
    //std::cout << "Exit <lexpr>" << std::endl;
}

Node* Parser::pexpr(){
    // std::cout << " Enter <pexpr>" << std::endl;

    if(nextToken.code == TokenCodes::LEFT_PAREN){
        nextToken = lex.getToken();
        expr();
        if(nextToken.code != TokenCodes::RIGHT_PAREN){
            error();
        }
    }else if(nextToken.code == TokenCodes::VAR){
        /* Maak VAR token aan */
        nextToken = lex.getToken();
    }else {
        error();
    }

    return nullptr;
    //std::cout << "Exit <pexpr>" << std::endl;
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
        atNode->setTokenCode(TokenCodes::AT_SIGN);
        atNode->setLeftChild(left);
        atNode->setRightChild(right);
        return atNode;
    }
    return left;
}

void Parser::dot(){
    ast.dot("test.dot");
}