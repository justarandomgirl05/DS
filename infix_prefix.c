#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int top;
    char items[MAX];
} CharStack;

void pushChar(CharStack *s, char c)
{
    if (s->top < MAX - 1)
        s->items[++(s->top)] = c;
}

char popChar(CharStack *s)
{
    if (s->top == -1)
        return '\0';
    return s->items[(s->top)--];
}

char peekChar(CharStack *s)
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top];
}

typedef struct
{
    int top;
    int items[MAX];
} IntStack;

void pushInt(IntStack *s, int val)
{
    if (s->top < MAX - 1)
        s->items[++(s->top)] = val;
}

int popInt(IntStack *s)
{
    if (s->top == -1)
        return -1;
    return s->items[(s->top)--];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    CharStack stack;
    stack.top = -1;
    int len = strlen(infix);
    char revInfix[MAX], tempPrefix[MAX];
    int j = 0;

    // Step 1: Reverse infix expression and swap '(' with ')'
    strcpy(revInfix, infix);
    reverse(revInfix);
    for (int i = 0; i < len; i++)
    {
        if (revInfix[i] == '(')
            revInfix[i] = ')';
        else if (revInfix[i] == ')')
            revInfix[i] = '(';
    }

    // Step 2: Convert reversed infix to postfix (stored in tempPrefix)
    for (int i = 0; i < len; i++)
    {
        char c = revInfix[i];

        if (isalnum(c))
        {
            tempPrefix[j++] = c; // operand goes directly
        }
        else if (c == '(')
        {
            pushChar(&stack, c);
        }
        else if (c == ')')
        {
            while (stack.top != -1 && peekChar(&stack) != '(')
                tempPrefix[j++] = popChar(&stack);
            popChar(&stack); // pop '('
        }
        else if (isOperator(c))
        {
            while (stack.top != -1 && precedence(peekChar(&stack)) > precedence(c))
                tempPrefix[j++] = popChar(&stack);
            pushChar(&stack, c);
        }
    }

    while (stack.top != -1)
        tempPrefix[j++] = popChar(&stack);

    tempPrefix[j] = '\0';

    // Step 3: Reverse postfix to get prefix
    reverse(tempPrefix);
    strcpy(prefix, tempPrefix);
}

// Evaluate prefix expression (single digit operands only)
int evaluatePrefix(char *prefix)
{
    IntStack stack;
    stack.top = -1;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isdigit(c))
        {
            pushInt(&stack, c - '0');
        }
        else if (isOperator(c))
        {
            int op1 = popInt(&stack);
            int op2 = popInt(&stack);
            int res = 0;

            switch (c)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            case '^':
            {
                res = 1;
                for (int k = 0; k < op2; k++)
                    res *= op1;
            }
            break;
            }
            pushInt(&stack, res);
        }
    }
    return popInt(&stack);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression (single digit operands only): ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
