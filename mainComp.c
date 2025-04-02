#include <stdio.h>
#include "semantic.c"

int main() {
    char userInput[256];
    printf("\n\nEnter an arithmetic expression: ");
    fgets(userInput, sizeof(userInput), stdin);
    setInput(userInput);
    
    if (parse()) {
        if (semanticCheck()) {
            printf("Valid arithmetic expression.\n");
        } else {
            printf("Semantic error.\n");
        }
    } else {
        printf("Syntax error.\n");
    }
    return 0;
}