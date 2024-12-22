// Open Addressing: If a collision occurs, we search for the next available slot in the table.
/*
Linear Probing is a collision resolution technique in hash tables.
When a collision occurs (i.e., two keys hash to the same index),
linear probing resolves the collision by searching for the next available slot in a sequential manner.

Formula:
    Index=(h(k)+i)modtable size

where:
    - h(k) is the hash function.
    - i is the probe number (0, 1, 2, ...).
    - table size is the size of the hash table.
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1   // Marker for empty slot
#define DELETED -2 // Marker for deleted slot

// Create a hash table with open addressing (linear probing)
int hashTable[TABLE_SIZE];

// Hash function to compute index
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Insert a key into the hash table
void insert(int key)
{
    int index = hashFunction(key);

    // Linear probing: search for the next empty or deleted slot
    while (hashTable[index] != EMPTY && hashTable[index] != DELETED)
    {
        index = (index + 1) % TABLE_SIZE; // Move to next index (circular)
    }

    hashTable[index] = key;
}

// Search for a key in the hash table
int search(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;

    // Linear probing: search for the key
    while (hashTable[index] != EMPTY)
    {
        if (hashTable[index] == key)
        {
            return index; // Key found
        }
        index = (index + 1) % TABLE_SIZE;

        // If we loop back to the original index, the key isn't present
        if (index == originalIndex)
        {
            break;
        }
    }
    return -1; // Key not found
}

// Delete a key from the hash table
void delete(int key)
{
    int index = search(key);

    if (index != -1)
    {
        hashTable[index] = DELETED; // Mark the slot as deleted
        printf("Key %d deleted.\n", key);
    }
    else
    {
        printf("Key %d not found.\n", key);
    }
}

// Display the hash table
void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
        {
            printf("Index %d: EMPTY\n", i);
        }
        else if (hashTable[i] == DELETED)
        {
            printf("Index %d: DELETED\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    // Initialize the hash table with EMPTY slots
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = EMPTY;
    }

    // Insert some keys
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);

    // Display the hash table
    display();

    // Search for keys
    int key = 22;
    int index = search(key);
    if (index != -1)
    {
        printf("Key %d found at index %d.\n", key, index);
    }
    else
    {
        printf("Key %d not found.\n", key);
    }

    // Delete a key
    delete (32);
    delete (99); // This key is not in the table

    // Display the hash table after deletion
    display();

    return 0;
}
