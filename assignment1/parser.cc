#include "parser.h"

void Parser::expr(){
    std::cout << " Enter <expr>" << std::endl;

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

    std::cout << "Exit <expr>" << std::endl;
}

void Parser::expr_(){
    std::cout << " Enter <expr_>" << std::endl;


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

    std::cout << "Exit <expr_>" << std::endl;
}

void Parser::parse(){
    lex.getChar();
    nextToken = lex.getToken();
    expr();
}

void Parser::error(){
    passed = false;
    std::cout << "Error" << std::endl;
}