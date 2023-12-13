#include "parser.h"

void Parser::start(){
    ast.destroy();
    ast.setRoot(expr());
    if(nextToken.code != TokenCodes::EOF_){
        error();
    }
}

Node* Parser::expr(){
    std::cout << " Enter <expr> " << std::endl;
   
    lexpr();
    expr_();

    std::cout << "Exit <expr>" << std::endl;
    return nullptr;
}

Node* Parser::expr_(){
    std::cout << " Enter <expr_>" << std::endl;

    // Hoe bepaal je of je de empty string moet nemen?
    if(nextToken.code == TokenCodes::LAMBDA ||
       nextToken.code == TokenCodes::VAR ||
       nextToken.code == TokenCodes::LEFT_PAREN){
        lexpr();
        expr_();
    }

    std::cout << "Exit <expr_>" << std::endl;
    return nullptr;
}

Node* Parser::lexpr(){
    std::cout << " Enter <lexpr>" << std::endl;

    if(nextToken.code == TokenCodes::LAMBDA){
        updateToken();
        if(nextToken.code == TokenCodes::VAR){
            /* TODO: Maak Lambda token aan */
            
            lexpr();
        }else{
            error();
        }
    }else{
        pexpr();
    }
    
    std::cout << "Exit <lexpr>" << std::endl;
    return nullptr;
}

Node* Parser::pexpr(){
    std::cout << " Enter <pexpr>" << std::endl;

    if(nextToken.code == TokenCodes::LEFT_PAREN){
        updateToken();;
        expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            updateToken();;
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::VAR){
        /* Maak VAR token aan */
        updateToken();
    }else {
        error();
    }

    std::cout << "Exit <pexpr>" << std::endl;
    return nullptr;
}

void Parser::parse(std::string expression){
    currentExpression = expression;
    lex.setExpression(expression);
    lex.getChar();
    updateToken();
    start();
}

void Parser::error(){
    passed = false;
    std::cout << "Invalid Syntax at expression " << currentExpression << std::endl;
    std::cout << "Error at token: " << nextToken.toString() << std::endl;
    std::cout << "Exiting Program" << std::endl;
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

void Parser::updateToken(){
    nextToken = lex.getToken();
    std::cout << "new Token: " << nextToken.toString() << std::endl;
}