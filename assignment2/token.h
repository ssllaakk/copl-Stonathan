#include <string>
#include "constantes.h"

#ifndef TOKEN
#define TOKEN

struct Token
{
    TokenCodes code;
    std::string var;
    
    std::string toString();
};

#endif