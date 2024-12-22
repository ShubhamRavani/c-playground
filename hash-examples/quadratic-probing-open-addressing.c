/*
Quadratic Probing is a collision resolution technique used in hash tables.
When a collision occurs (i.e., two keys hash to the same index),
quadratic probing searches for the next available slot in a quadratic manner.

Formula:
    Index=(h(k)+c1*i+c2*i^2)%TABLE_SIZE

where:
    - h(k) is the hash value of the key,
    - c1 and c2 are constants,
    - i is the probing sequence number,
    - TABLE_SIZE is the size of the hash table.
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Size of the hash table

// Function to calculate the hash value
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

// Function to insert a key using quadratic probing
void insert(int hashTable[], int key)
{
    int index = hashFunction(key);
    int i = 0;

    // Quadratic probing to find the next available slot
    while (hashTable[(index + i * i) % TABLE_SIZE] != -1 && i < TABLE_SIZE)
    {
        i++;
    }

    // If the table is full, insertion fails
    if (i >= TABLE_SIZE)
    {
        printf("Hash table is full. Unable to insert key: %d\n", key);
        return;
    }

    hashTable[(index + i * i) % TABLE_SIZE] = key;
    printf("Inserted key %d at index %d\n", key, (index + i * i) % TABLE_SIZE);
}

// Function to search for a key using quadratic probing
int search(int hashTable[], int key)
{
    int index = hashFunction(key);
    int i = 0;

    // Quadratic probing to find the key
    while (hashTable[(index + i * i) % TABLE_SIZE] != key && hashTable[(index + i * i) % TABLE_SIZE] != -1 && i < TABLE_SIZE)
    {
        i++;
    }

    // Key found
    if (hashTable[(index + i * i) % TABLE_SIZE] == key)
    {
        return (index + i * i) % TABLE_SIZE;
    }

    // Key not found
    return -1;
}

// Function to display the hash table
void displayHashTable(int hashTable[])
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            printf("Index %d: Empty\n", i);
        }
        else
        {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    int hashTable[TABLE_SIZE];

    // Initialize hash table with -1 (indicating empty slots)
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }

    // Insert keys into the hash table
    insert(hashTable, 12);
    insert(hashTable, 22);
    insert(hashTable, 42);
    insert(hashTable, 32);

    // Display the hash table
    displayHashTable(hashTable);

    // Search for keys
    int keyToSearch = 22;
    int searchResult = search(hashTable, keyToSearch);
    if (searchResult != -1)
    {
        printf("Key %d found at index %d\n", keyToSearch, searchResult);
    }
    else
    {
        printf("Key %d not found in the hash table\n", keyToSearch);
    }

    return 0;
}
