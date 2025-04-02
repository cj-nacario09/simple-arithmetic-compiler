#ifndef PARSER_H
#define PARSER_H

#include "lexer.c"

static Token currentToken;

void advance() {
    currentToken = getNextToken();
}

int expression();
int term();
int factor();

int parse() {
    advance();
    if (!expression()) return 0;
    if (currentToken.type != TOKEN_EOF) {
        printf("\nSyntax error: Unexpected token '%s'\n", currentToken.lexeme);
        return 0;
    }
    return 1;
}

int expression() {
    printf("Entering expression\n");
    if (!term()) return 0;
    while (currentToken.type == TOKEN_PLUS || currentToken.type == TOKEN_MINUS) {
        printf("Operator: %s\n\n", currentToken.lexeme);
        advance();
        if (!term()) return 0;
    }
    printf("Exiting expression\n");
    return 1;
}

int term() {
    printf("Entering term\n");
    if (!factor()) return 0;
    while (currentToken.type == TOKEN_MUL || currentToken.type == TOKEN_DIV) {
        printf("Operator: %s\n\n", currentToken.lexeme);
        advance();
        if (!factor()) return 0;
    }
    printf("Exiting term\n");
    return 1;
}

int factor() {
    if (currentToken.type == TOKEN_INT) {
        printf("Integer: %s\n\n", currentToken.lexeme);
        advance();
        return 1;
    } else if (currentToken.type == TOKEN_LPAREN) {
        printf("Opening parenthesis\n\n");
        advance();
        if (!expression()) return 0;
        if (currentToken.type == TOKEN_RPAREN) {
            printf("Closing parenthesis\n\n");
            advance();
            return 1;
        } else {
            printf("\nSyntax error: Missing closing parenthesis\n");
            return 0;
        }
    }
    printf("\nSyntax error: Unexpected token '%s'\n", currentToken.lexeme);
    return 0;
}

#endif