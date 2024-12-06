#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Delete the head node
struct Node *deleteHead(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->next == head)
    { // Single node case
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *tail = head;

    while (tail->next != head)
    {
        tail = tail->next;
    }

    head = head->next;
    tail->next = head;

    free(temp);
    return head;
}

// Display the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
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
    third->next = head;

    printf("Original List: ");
    display(head);

    head = deleteHead(head); // Delete the head node

    printf("List after deletion: ");
    display(head);

    return 0;
}
