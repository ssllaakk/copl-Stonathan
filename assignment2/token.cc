#include "token.h"

std::string Token::toString()
{
        std::string s = "";
        
        switch (code)
        {
            case TokenCodes::VAR:
                s = "VAR";
                break;
            case TokenCodes::LAMBDA:
                s = "LAMBDA";
                break;
            case TokenCodes::LEFT_PAREN:
                s = "LEFT_PAREN";
                break;
            case TokenCodes::RIGHT_PAREN:
                s = "RIGHT_PAREN";
                break;
            case TokenCodes::AT_SIGN:
                s = "AT_SIGN";
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