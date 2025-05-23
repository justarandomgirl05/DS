#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// a) Find first non-repeating element
void firstNonRepeating()
{
    int n, i, j, flag;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("First non-repeating element is: %d\n", arr[i]);
            return;
        }
    }
    printf("No non-repeating element found.\n");
}

// b) Find address of array
void printArrayAddress()
{
    int arr[5], i;
    printf("Enter 5 elements:\n");
    for (i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    printf("Base address of array: %p\n", arr);
    for (i = 0; i < 5; i++)
        printf("Address of arr[%d] = %p\n", i, &arr[i]);
}

// c) Saddle point: min in row and max in column
void saddlePoint()
{
    int a[10][10], i, j, k, r, c, min, col, isSaddle = 0;
    printf("Enter rows and cols: ");
    scanf("%d%d", &r, &c);
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < r; i++)
    {
        min = a[i][0];
        col = 0;
        for (j = 1; j < c; j++)
        {
            if (a[i][j] < min)
            {
                min = a[i][j];
                col = j;
            }
        }
        for (k = 0; k < r; k++)
        {
            if (a[k][col] > min)
                break;
        }
        if (k == r)
        {
            printf("Saddle Point found at [%d][%d]: %d\n", i, col, min);
            isSaddle = 1;
        }
    }
    if (!isSaddle)
        printf("No saddle point found.\n");
}

// d) Check if matrix is Magic Square
void isMagicSquare()
{
    int a[10][10], i, j, n, sum, diag1 = 0, diag2 = 0;
    printf("Enter order of square matrix (n): ");
    scanf("%d", &n);
    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    sum = 0;
    for (j = 0; j < n; j++)
        sum += a[0][j]; // Sum of first row

    // Check rows and columns
    for (i = 0; i < n; i++)
    {
        int row = 0, col = 0;
        for (j = 0; j < n; j++)
        {
            row += a[i][j];
            col += a[j][i];
        }
        if (row != sum || col != sum)
        {
            printf("Not a magic square.\n");
            return;
        }
    }

    // Check diagonals
    for (i = 0; i < n; i++)
    {
        diag1 += a[i][i];
        diag2 += a[i][n - 1 - i];
    }

    if (diag1 != sum || diag2 != sum)
    {
        printf("Not a magic square.\n");
    }
    else
    {
        printf("Yes! It is a magic square.\n");
    }
}

// e) Sparse matrix representation
void sparseMatrix()
{
    int a[10][10], i, j, r, c, count = 0;
    printf("Enter rows and cols: ");
    scanf("%d%d", &r, &c);
    printf("Enter matrix elements:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                count++;
        }

    printf("Sparse matrix representation:\n");
    printf("Row Col Value\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != 0)
                printf("%d    %d    %d\n", i, j, a[i][j]);
}

int main()
{
    int choice;

    while (1)
    {
        printf("1. First non-repeating element in array\n");
        printf("2. Find address of array\n");
        printf("3. Find saddle point in matrix\n");
        printf("4. Check magic square\n");
        printf("5. Sparse matrix representation\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            firstNonRepeating();
            break;
        case 2:
            printArrayAddress();
            break;
        case 3:
            saddlePoint();
            break;
        case 4:
            isMagicSquare();
            break;
        case 5:
            sparseMatrix();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
