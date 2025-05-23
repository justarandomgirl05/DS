#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Create new node with given data
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Print the list
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Split list into two halves
void splitList(Node *head, Node **front, Node **back)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

// Merge two sorted lists
Node *mergeLists(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *result = NULL;
    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}

// Merge sort on linked list
void mergeSort(Node **headRef)
{
    Node *head = *headRef;
    if (head == NULL || head->next == NULL)
        return;

    Node *a;
    Node *b;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeLists(a, b);
}

// Main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, value;

    // Ask user how many elements
    printf("Enter number of elements in the linked list: ");
    scanf("%d", &n);

    // Take input values from user
    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        Node *new_node = newNode(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Print original list
    printf("\nOriginal linked list:\n");
    printList(head);

    // Sort list
    mergeSort(&head);

    // Print sorted list
    printf("\nSorted linked list:\n");
    printList(head);

    return 0;
}
