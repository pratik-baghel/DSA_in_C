#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSION 100

char stack[MAX_EXPRESSION];
int top = -1;

int push(char symbol)
{
    if (top == MAX_EXPRESSION - 1) {
        return 0;
    }

    stack[++top] = symbol;
    return 1;
}

char pop(void)
{
    return top == -1 ? '\0' : stack[top--];
}

char peek(void)
{
    return top == -1 ? '\0' : stack[top];
}

int precedence(char symbol)
{
    switch (symbol) {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default:  return 0;
    }
}

int is_operator(char symbol)
{
    return symbol == '+' || symbol == '-' || symbol == '*' ||
           symbol == '/' || symbol == '^';
}

int infix_to_postfix(const char *infix, char *postfix)
{
    int output = 0;

    for (int input = 0; infix[input] != '\0'; ++input) {
        char symbol = infix[input];

        if (isspace((unsigned char)symbol)) {
            continue;
        }

        if (isalnum((unsigned char)symbol)) {
            postfix[output++] = symbol;
        } else if (symbol == '(') {
            if (!push(symbol)) return 0;
        } else if (symbol == ')') {
            while (peek() != '\0' && peek() != '(') {
                postfix[output++] = pop();
            }
            if (pop() != '(') return 0;
        } else if (is_operator(symbol)) {
            while (peek() != '\0' && peek() != '(' &&
                   (precedence(peek()) > precedence(symbol) ||
                    (precedence(peek()) == precedence(symbol) && symbol != '^'))) {
                postfix[output++] = pop();
            }
            if (!push(symbol)) return 0;
        } else {
            return 0;
        }
    }

    while (peek() != '\0') {
        char symbol = pop();
        if (symbol == '(') return 0;
        postfix[output++] = symbol;
    }

    postfix[output] = '\0';
    return 1;
}

int main(void)
{
    char infix[MAX_EXPRESSION];
    char postfix[MAX_EXPRESSION];

    printf("Enter infix expression: ");
    if (fgets(infix, sizeof infix, stdin) == NULL) return 1;

    infix[strcspn(infix, "\n")] = '\0';
    if (!infix_to_postfix(infix, postfix)) {
        fprintf(stderr, "Invalid expression.\n");
        return 1;
    }

    printf("Postfix: %s\n", postfix);
    return 0;
}