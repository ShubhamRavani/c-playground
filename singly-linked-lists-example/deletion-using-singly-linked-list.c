#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Delete a node at a specific position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    struct Node *temp = head;

    if (position == 0)
    {
        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position out of bounds!\n");
        return head;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;

    free(nodeToDelete);
    return head;
}

// Display the linked list
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

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Original List: ");
    display(head);

    head = deleteAtPosition(head, 1); // Delete node at position 1

    printf("List after deletion: ");
    display(head);

    return 0;
}
