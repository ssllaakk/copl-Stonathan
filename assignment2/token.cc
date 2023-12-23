#include "token.h"

std::string Token::toString()
{
        std::string s = "";
        
        switch (code)
        {
            case TokenCodes::VAR:
                s = "";
                break;
            case TokenCodes::LAMBDA:
                s = "λ";
                break;
            case TokenCodes::LEFT_PAREN:
                s = "(";
                break;
            case TokenCodes::RIGHT_PAREN:
                s = ")";
                break;
            case TokenCodes::AT_SIGN:
                s = "@";
                break;
            case TokenCodes::ERROR:
                s = "ERROR";
                break;
            case TokenCodes::EOF_:
                s = "EOF_";
                break;
        }
        s += " " + var;
        return s;
    }