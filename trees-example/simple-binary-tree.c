#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// In-order traversal (left, root, right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Visit left subtree
        printf("%d ", root->data); // Visit node
        inorder(root->right);      // Visit right subtree
    }
}

int main()
{
    // Creating nodes
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Traversing the tree in-order
    printf("In-order Traversal: ");
    inorder(root);

    return 0;
}
