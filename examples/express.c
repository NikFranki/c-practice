#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_MULTIPLY,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

Token currentToken;

void nextToken() {
    int c = getchar();
    if (c == '+') {
        currentToken.type = TOKEN_PLUS;
    } else if (c == '*') {
        currentToken.type = TOKEN_MULTIPLY;
    } else if (isdigit(c)) {
        ungetc(c, stdin);
        scanf("%d", &currentToken.value);
        currentToken.type = TOKEN_INT;
    } else if (c == EOF) {
        currentToken.type = TOKEN_EOF;
    } else {
        currentToken.type = TOKEN_EOF;
    }
}

int factor();

int term() {
    int result = factor();
    while (currentToken.type == TOKEN_MULTIPLY) {
        nextToken();
        result *= factor();
    }
    return result;
}

int factor() {
    if (currentToken.type == TOKEN_INT) {
        int value = currentToken.value;
        nextToken();
        return value;
    } else {
        return 0; // Error
    }
}

int main() {
    nextToken();
    int result = term();
    printf("Result: %d\n", result);
    return 0;
}
