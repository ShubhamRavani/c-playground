// Chaining: In case of collisions, each index in the hash table stores a linked list of keys

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define a node structure for chaining (linked list)
struct Node
{
    int key;
    struct Node *next;
};

// Create a hash table
struct Node *hashTable[TABLE_SIZE];

// Hash function to map a key to a table index
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key)
{
    int index = hashFunction(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search for a key in the hash table
int search(int key)
{
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return 1; // Found the key
        }
        temp = temp->next;
    }
    return 0; // Key not found
}

// Display the hash table
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Index %d: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    // Initialize the hash table
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    // Insert some keys
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);

    // Display the hash table
    printf("Hash Table:\n");
    display();

    // Search for keys
    int key = 22;
    if (search(key))
    {
        printf("Key %d found in the table.\n", key);
    }
    else
    {
        printf("Key %d not found in the table.\n", key);
    }

    key = 99;
    if (search(key))
    {
        printf("Key %d found in the table.\n", key);
    }
    else
    {
        printf("Key %d not found in the table.\n", key);
    }

    return 0;
}
