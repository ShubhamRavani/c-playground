#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by value
struct Node *deleteNode(struct Node *head, int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);
    return head;
}

int main()
{
    struct Node *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    display(head);

    insertAtEnd(head, 40);
    display(head);

    head = deleteNode(head, 20);
    display(head);

    return 0;
}
