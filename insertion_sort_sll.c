#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into the sorted part of the list
struct Node *sortedInsert(struct Node *sorted, struct Node *newNode)
{
    if (sorted == NULL || newNode->data < sorted->data) // if list empty newnode should be first, if newnode data is smaller than first node in list, newnode should be first
    {
        newNode->next = sorted;
        return newNode;
    }

    struct Node *current = sorted;
    while (current->next != NULL && current->next->data < newNode->data)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return sorted;
}

// Function to perform insertion sort on the list
struct Node *insertionSort(struct Node *head)
{
    struct Node *sorted = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }
    return sorted;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Main function
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = insertionSort(head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
