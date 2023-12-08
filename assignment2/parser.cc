#include "parser.h"

void Parser::start(){
    ast.destroy();
    ast.setRoot(new Node());
    ast.getRoot()->setLeftChild(expr());
    if(nextToken.code != TokenCodes::EOF_){
        error();
    }
}

Node* Parser::expr(){
    //std::cout << " Enter <expr> " << std::endl;
    Node* n = new Node();

    if(nextToken.code == TokenCodes::VAR){
        n->setTokenCode(TokenCodes::VAR);
        n->setTokenVar(nextToken.var);
        nextToken = lex.getToken();
        // n is VAR of @ met VAR als linker kind en expr_ als rechterkind
        n = buildSubTree(n , expr_());
        // std::cout << "Exit <expr>" << std::endl;
        return n;
    }else if(nextToken.code == TokenCodes::LEFT_PAREN){
        nextToken = lex.getToken();
        // n is de expressie tussen haakjes
        n = expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            nextToken = lex.getToken();
            // n is (expr) of @ met expr als linker kind en expr_ als rechterkind
            n = buildSubTree(n , expr_());
            // std::cout << "Exit <expr>" << std::endl;
            return n;
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::LAMBDA){
        n->setTokenCode(TokenCodes::LAMBDA);
        nextToken = lex.getToken();
        if(nextToken.code == TokenCodes::VAR){
            n->setTokenVar(nextToken.var);
            nextToken = lex.getToken();
            // lambda node aanmaken en kind eronder plakken     
            Node* kind = expr();
            n->setLeftChild(kind);
            Node* buurman = expr_();
            n = buildSubTree(n, buurman);
            // std::cout << "Exit <expr>" << std::endl;

            return n;
        }else{
            error();
        }
    }else{
        error();
    }
    
    // std::cout << "Exit <expr>" << std::endl;
    return nullptr;
}

Node* Parser::expr_(){
    // std::cout << " Enter <expr_>" << std::endl;
     Node* n = new Node();

    if(nextToken.code == TokenCodes::VAR){
        n->setTokenCode(TokenCodes::VAR);
        n->setTokenVar(nextToken.var);
        nextToken = lex.getToken();
        // n is VAR of @ met VAR als linker kind en expr_ als rechterkind
        n = buildSubTree(n , expr_());
        // std::cout << "Exit <expr_>" << std::endl;
        return n;
    }else if(nextToken.code == TokenCodes::LEFT_PAREN){
        nextToken = lex.getToken();
        // n is de expressie tussen haakjes
        n = expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            nextToken = lex.getToken();
            // n is (expr) of @ met expr als linker kind en expr_ als rechterkind
            n = buildSubTree(n , expr_());
            // std::cout << "Exit <expr_>" << std::endl;
            return n;
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::LAMBDA){
        n->setTokenCode(TokenCodes::LAMBDA);
        nextToken = lex.getToken();
        if(nextToken.code == TokenCodes::VAR){
            n->setTokenVar(nextToken.var);
            nextToken = lex.getToken();
            // lambda node aanmaken en kind eronder plakken   
            Node* l = expr();
            Node* r = expr_();  
            n->setLeftChild(buildSubTree(l,r));
            // std::cout << "Exit <expr_>" << std::endl;
            return n;
        }else{
            error();
        }
    }

    //std::cout << "Exit <expr_>" << std::endl;
    return nullptr;

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