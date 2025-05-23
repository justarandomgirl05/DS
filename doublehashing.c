#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Primary hash function
int hash1(int key)
{
    return key % TABLE_SIZE;
}

// Secondary hash function (must not return 0)
int hash2(int key)
{
    return 7 - (key % 7); // Use a prime smaller than TABLE_SIZE
}

void insert(int key)
{
    int index = hash1(key);
    int step = hash2(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int newIndex = (index + i * step) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY)
        {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        }
    }
    printf("Hash table is full, couldn't insert %d\n", key);
}

void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != EMPTY)
            printf("%d --> %d\n", i, hashTable[i]);
        else
            printf("%d --> EMPTY\n", i);
    }
}

int main()
{
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;

    int n, key;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
