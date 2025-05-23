#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Stack Functions
void push(int value)
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

int pop()
{
    if (top == -1)
        return 1; // For factorial, multiplying by 1 won't change the result
    else
        return stack[top--];
}

int peek(int index_from_top)
{
    if (top - index_from_top < 0)
        return 0;
    else
        return stack[top - index_from_top];
}

// Factorial Function Using Stack
int factorial_using_stack(int n)
{
    int result = 1;
    top = -1; // Reset stack

    for (int i = n; i >= 1; i--)
        push(i);

    while (top != -1)
        result *= pop();

    return result;
}

// Fibonacci Function Using Stack
void fibonacci_using_stack(int terms)
{
    top = -1; // Reset stack

    push(0);
    push(1);

    printf("Fibonacci Series: ");
    printf("%d %d ", peek(1), peek(0));

    for (int i = 2; i < terms; i++)
    {
        int a = peek(1);
        int b = peek(0);
        int next = a + b;
        printf("%d ", next);
        push(next);
    }

    printf("\n");
}

// Main Function with Menu
int main()
{
    int choice, number;

    do
    {
        printf("\nMenu:\n");
        printf("1. Factorial\n");
        printf("2. Fibonacci series\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to find factorial: ");
            scanf("%d", &number);
            printf("Factorial of %d is %d\n", number, factorial_using_stack(number));
            break;

        case 2:
            printf("Enter number of terms for Fibonacci series: ");
            scanf("%d", &number);
            fibonacci_using_stack(number);
            break;

        case 3:
            printf("Exiting\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
