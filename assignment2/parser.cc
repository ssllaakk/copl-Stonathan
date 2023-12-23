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
    Node* n = nullptr;

    Node* a = lexpr(); // <-- linker kind van @
    Node* b = expr_(a); // <-- rechter kind van @
    if(b == nullptr){
        n = a;
    }else{
        n = b;
    }
    std::cout << "Exit <expr>" << std::endl;
    return n;
}

Node* Parser::expr_(Node* left){
    std::cout << " Enter <expr_>" << std::endl;
    Node* n = nullptr;

    if(nextToken.code == TokenCodes::LAMBDA ||
       nextToken.code == TokenCodes::VAR ||
       nextToken.code == TokenCodes::LEFT_PAREN){
        
        Node* a = lexpr(); // <-- linker kind van @
        Node* nwLeft = buildSubTree(left,a);

        Node* b = expr_(nwLeft); // <-- rechter kind van @
        if(b == nullptr){
            n = nwLeft;
        }else{
            n = b;
        }

    }

    std::cout << "Exit <expr_>" << std::endl;
    return n;
}

Node* Parser::lexpr(){
    std::cout << " Enter <lexpr>" << std::endl;
    Node* n;

    if(nextToken.code == TokenCodes::LAMBDA){
        updateToken();
        if(nextToken.code == TokenCodes::VAR){
            /* Maak Lambda token aan */
            n = new Node();

            n->setTokenCode(TokenCodes::LAMBDA);
            n->setTokenVar(nextToken.var);
            
            updateToken();

            Node* child = lexpr();
            n->setLeftChild(child);
        }else{
            error();
        }
    }else{
        n = pexpr();
    }
    
    std::cout << "Exit <lexpr>" << std::endl;
    return n;
}

Node* Parser::pexpr(){
    std::cout << " Enter <pexpr>" << std::endl;
    Node* n;

    if(nextToken.code == TokenCodes::LEFT_PAREN){
        updateToken();;
        n = expr();
        if(nextToken.code == TokenCodes::RIGHT_PAREN){
            updateToken();;
        }else{
            error();
        }
    }else if(nextToken.code == TokenCodes::VAR){
        /* Maak VAR token aan */
        n = new Node();

        n->setTokenCode(TokenCodes::VAR);
        n->setTokenVar(nextToken.var);

        updateToken();
    }else {
        error();
    }

    std::cout << "Exit <pexpr>" << std::endl;
    return n;
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