#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Stack structure for non-recursive traversals
#define MAX 100
Node *stack[MAX];
int top = -1;

void push(Node *node)
{
    if (top < MAX - 1)
        stack[++top] = node;
}

Node *pop()
{
    if (top >= 0)
        return stack[top--];
    return NULL;
}

int isEmpty()
{
    return top == -1;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
        return newNode;

    Node *current = root;
    Node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Non-recursive Pre-order Traversal
void preorder(Node *root)
{
    if (root == NULL)
        return;

    push(root);
    while (!isEmpty())
    {
        Node *current = pop();
        printf("%d ", current->data);

        // Push right first so left is processed first
        if (current->right)
            push(current->right);
        if (current->left)
            push(current->left);
    }
    printf("\n");
}

// Non-recursive Post-order Traversal using 2 stacks
void postorder(Node *root)
{
    if (root == NULL)
        return;

    Node *stack1[MAX];
    Node *stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1)
    {
        Node *node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 != -1)
        printf("%d ", stack2[top2--]->data);

    printf("\n");
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    push(root);
    while (!isEmpty())
    {
        Node *node = pop();
        count++;

        if (node->right)
            push(node->right);
        if (node->left)
            push(node->left);
    }
    return count;
}

void printLeafNodes(Node *root)
{
    if (root == NULL)
        return;

    push(root);
    while (!isEmpty())
    {
        Node *node = pop();
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->data);
        if (node->right)
            push(node->right);
        if (node->left)
            push(node->left);
    }
    printf("\n");
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n1. Insert\n2. Pre-order\n3. Post-order\n4. Total Nodes\n5. Leaf Nodes\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Pre-order Traversal: ");
            preorder(root);
            break;
        case 3:
            printf("Post-order Traversal: ");
            postorder(root);
            break;
        case 4:
            printf("Total Nodes: %d\n", countNodes(root));
            break;
        case 5:
            printf("Leaf Nodes: ");
            printLeafNodes(root);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
