#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    TOKEN_INT, TOKEN_PLUS, TOKEN_MINUS, TOKEN_MUL, TOKEN_DIV, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_EOF, TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[64]; 
} Token;

static char input[256];
static int pos = 0;

void setInput(const char* src) {
    strncpy(input, src, 255);
    pos = 0;
    printf("Token to be tokenized: %s\n", input);
}

Token getNextToken() {
    Token token;
    while (input[pos] == ' ' || input[pos] == '\n') pos++;

    if (isdigit(input[pos])) {
        token.type = TOKEN_INT;
        int start = pos;
        while (isdigit(input[pos])) pos++; // Read the full number
        int length = pos - start;
        strncpy(token.lexeme, &input[start], length);
        token.lexeme[length] = '\0'; // Null terminate the string
        printf("Token: %s\nToken type: Token_Number\n", token.lexeme);
    } else if (input[pos] == '+') {
        token.type = TOKEN_PLUS;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_PLUS\n", token.lexeme);
    } else if (input[pos] == '-') {
        token.type = TOKEN_MINUS;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_MINUS\n", token.lexeme);
    } else if (input[pos] == '*') {
        token.type = TOKEN_MUL;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_STAR\n", token.lexeme);
    } else if (input[pos] == '/') {
        token.type = TOKEN_DIV;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_DIV\n", token.lexeme);
    } else if (input[pos] == '(') {
        token.type = TOKEN_LPAREN;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_LEFT_PARENT\n", token.lexeme);
    } else if (input[pos] == ')') {
        token.type = TOKEN_RPAREN;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Token: %s\nToken type: Token_RIGHT_PARENT\n", token.lexeme);
    } else if (input[pos] == '\0') {
        token.type = TOKEN_EOF;
        token.lexeme[0] = '\0';
    } else {
        token.type = TOKEN_ERROR;
        token.lexeme[0] = input[pos++];
        token.lexeme[1] = '\0';
        printf("Invalid Token: %s\n", token.lexeme);
    }
    return token;
}

#endif