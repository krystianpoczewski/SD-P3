#include "HashTableBSTSeperateChaining.h"


unsigned int HashTableBSTSeperateChaining::HashFunction(int key)
{
    if (key < 0)
        key *= -1;
    return key % numberOfBuckets;
}

HashTableBSTSeperateChaining::~HashTableBSTSeperateChaining()
{
    for (int i = 0; i < numberOfBuckets; i++) {
        bst[i].Clear();
    }
    delete[] bst;
}

HashTableBSTSeperateChaining::HashTableBSTSeperateChaining()
{
    numberOfBuckets = 10;
    bst = new BinarySearchTree[numberOfBuckets];
}

void HashTableBSTSeperateChaining::Insert(int key, int value)
{
    unsigned int hashValue = HashFunction(key);
    bst[hashValue].Insert(key, value);
}

KeyValuePair HashTableBSTSeperateChaining::Remove(int key)
{
    unsigned int hashValue = HashFunction(key);
    KeyValuePair deletedValue =  bst[hashValue].Remove(key).value;
    return (KeyValuePair)deletedValue;
}

KeyValuePair* HashTableBSTSeperateChaining::Get(int key)
{
    unsigned int hashValue = HashFunction(key);
    Node* node = bst[hashValue].Find(key);
    if (node != nullptr) {
        return &(node->value);
    }
    else {
        return nullptr; 
    }
}

void HashTableBSTSeperateChaining::PrintAll() const
{
    for (int i = 0; i < numberOfBuckets; i++) {
        std::cout << "Bucket number " << i << ". " << std::endl;
        bst[i].PrintAll();
    }
}

int HashTableBSTSeperateChaining::GetSize() const
{
    int totalSize = 0;
    for (int i = 0; i < numberOfBuckets; i++) {
        totalSize += bst[i].GetSize();
    }
    return totalSize;
}

bool HashTableBSTSeperateChaining::IsEmpty() const
{
    for (int i = 0; i < numberOfBuckets; i++) {
        if (!bst[i].isEmpty())
            return false;
    }
    return true;
}

void HashTableBSTSeperateChaining::Clear()
{
    for (int i = 0; i < numberOfBuckets; i++){
        bst[i].Clear();
    }
}
