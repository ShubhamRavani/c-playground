#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data); // Create and return a new node
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data); // Insert into the left subtree
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data); // Insert into the right subtree
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);  // Visit left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Visit right subtree
    }
}

// Pre-order traversal (Root, Left, Right)
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);      // Visit root
        preorderTraversal(root->left);  // Visit left subtree
        preorderTraversal(root->right); // Visit right subtree
    }
}

// Post-order traversal (Left, Right, Root)
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);  // Visit left subtree
        postorderTraversal(root->right); // Visit right subtree
        printf("%d ", root->data);       // Visit root
    }
}

int main()
{
    struct Node *root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // In-order Traversal (Sorted order)
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Pre-order Traversal
    printf("Pre-order Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Post-order Traversal
    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
