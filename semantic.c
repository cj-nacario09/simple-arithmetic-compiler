#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "parser.c"

int semanticCheck() {
    Token prevToken;
    Token token;
    int firstToken = 1;
    
    while ((token = getNextToken()).type != TOKEN_EOF) {
        if (!firstToken && prevToken.type == TOKEN_DIV && token.type == TOKEN_INT && strcmp(token.lexeme, "0") == 0) {
            return 0; 
        }
        firstToken = 0;
        prevToken = token;
    }
    return 1; 
}

#endif
