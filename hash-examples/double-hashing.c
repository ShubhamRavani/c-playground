/*
Double Hashing is a collision resolution technique used in hash tables.
It uses a second hash function to calculate the step size for probing, which reduces clustering and ensures better distribution of keys.

Formula:
    Index=(h1(k)+i⋅h2(k))modtable size

where:
    - h1(k) is the primary hash function.
    - h2(k) is the secondary hash function (must not be 0).
    - i is the probe number (0, 1, 2, ...).
    - table size is the size of the hash table
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Size of the hash table

// Primary hash function
int hash1(int key)
{
    return key % TABLE_SIZE;
}

// Secondary hash function (must not return 0)
int hash2(int key)
{
    return 7 - (key % 7); // Using a prime number less than TABLE_SIZE
}

// Function to insert a key using double hashing
void insert(int hashTable[], int key)
{
    int index = hash1(key);    // Calculate the primary hash index
    int stepSize = hash2(key); // Calculate the step size using the secondary hash
    int i = 0;

    // Double hashing to find the next available slot
    while (hashTable[(index + i * stepSize) % TABLE_SIZE] != -1 && i < TABLE_SIZE)
    {
        i++;
    }

    // If the table is full, insertion fails
    if (i >= TABLE_SIZE)
    {
        printf("Hash table is full. Unable to insert key: %d\n", key);
        return;
    }

    hashTable[(index + i * stepSize) % TABLE_SIZE] = key;
    printf("Inserted key %d at index %d\n", key, (index + i * stepSize) % TABLE_SIZE);
}

// Function to search for a key using double hashing
int search(int hashTable[], int key)
{
    int index = hash1(key);
    int stepSize = hash2(key);
    int i = 0;

    // Double hashing to find the key
    while (hashTable[(index + i * stepSize) % TABLE_SIZE] != key &&
           hashTable[(index + i * stepSize) % TABLE_SIZE] != -1 &&
           i < TABLE_SIZE)
    {
        i++;
    }

    // Key found
    if (hashTable[(index + i * stepSize) % TABLE_SIZE] == key)
    {
        return (index + i * stepSize) % TABLE_SIZE;
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
    int keyToSearch = 42;
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
