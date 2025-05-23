#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    // Duplicate keys are not allowed
    return root;
}

// Find a key in BST
int find(struct Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (key == root->key)
        return 1;
    else if (key < root->key)
        return find(root->left, key);
    else
        return find(root->right, key);
}

// Mirror image of BST
void mirror(struct Node *root)
{
    if (root == NULL)
        return;

    // Swap left and right
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;
    int choice, key;

    while (1)
    {
        printf("\n--- BST Operations Menu ---\n");
        printf("1. Insert\n");
        printf("2. Find\n");
        printf("3. Mirror Image\n");
        printf("4. Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            printf("Inserted.\n");
            break;
        case 2:
            printf("Enter key to find: ");
            scanf("%d", &key);
            if (find(root, key))
                printf("Key %d found in the BST.\n", key);
            else
                printf("Key %d not found in the BST.\n", key);
            break;
        case 3:
            mirror(root);
            printf("BST mirrored.\n");
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}