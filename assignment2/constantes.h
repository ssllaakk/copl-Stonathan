#ifndef CONSTANTES
#define CONSTANTES

const int MAXLEN = 100;

// Character classes
// const int LETTER = 0;
// const int DIGIT = 1;
// const int UNKNOWN = 99;

// Token codes
// const int VAR = 10;
// const int LAMBDA = 20;
// const int LEFT_PAREN = 25;
// const int RIGHT_PAREN = 26;
// const int AT_SIGN = 100;
// const int ERROR = 404;

enum class CharacterClass{
    LETTER, DIGIT, UNKNOWN, EOF_
};

enum class TokenCodes {
    VAR, LAMBDA, LEFT_PAREN, RIGHT_PAREN, AT_SIGN, ERROR, EOF_
};


#endif