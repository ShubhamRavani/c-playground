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
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Helper function to find the minimum value in a BST
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root; // Base case: Node not found
    }

    // Traverse to the node to delete
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node to delete found
        // Case 1: Node with no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node with two children
        struct Node *temp = findMin(root->right);          // Find the in-order successor
        root->data = temp->data;                           // Replace data with successor's value
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

// In-order traversal to display the BST
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a leaf node
    printf("\nDeleting 20...\n");
    root = deleteNode(root, 20);
    printf("In-order Traversal after deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node with one child
    printf("\nDeleting 30...\n");
    root = deleteNode(root, 30);
    printf("In-order Traversal after deleting 30: ");
    inorderTraversal(root);
    printf("\n");

    // Delete a node with two children
    printf("\nDeleting 50...\n");
    root = deleteNode(root, 50);
    printf("In-order Traversal after deleting 50: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
