#include "parser.h"

void Parser::start(){
    expr();
    if(nextToken != EOF){
        error();
    }
}

void Parser::expr(){
    //std::cout << " Enter <expr>" << std::endl;

    if(nextToken == VAR){
        nextToken = lex.getToken();
        expr_();
    }else if(nextToken == LEFT_PAREN){
        nextToken = lex.getToken();
        expr();
        if(nextToken == RIGHT_PAREN){
            nextToken = lex.getToken();
            expr_();
        }else{
            error();
        }
    }else if(nextToken == LAMBDA){
        nextToken = lex.getToken();
        if(nextToken == VAR){
            nextToken = lex.getToken();
            expr();
            expr_();
        }else{
            error();
        }
    }else{
        error();
    }
    
    //std::cout << "Exit <expr>" << std::endl;
}

void Parser::expr_(){
    //std::cout << " Enter <expr_>" << std::endl;


    if(nextToken == VAR){
        nextToken = lex.getToken();
        expr_();
    }else if(nextToken == LEFT_PAREN){
        nextToken = lex.getToken();
        expr();
        if(nextToken == RIGHT_PAREN){
            nextToken = lex.getToken();
            expr_();
        }else{
            error();
        }
    }else if(nextToken == LAMBDA){
        nextToken = lex.getToken();
        if(nextToken == VAR){
            expr();
            expr_();
        }else{
            error();
        }
    }

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