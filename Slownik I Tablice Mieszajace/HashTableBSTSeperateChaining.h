#pragma once
#include "BinarySearchTree.h"
#include "HashTable.h"

class HashTableBSTSeperateChaining : public HashTable, protected BinarySearchTree
{
private:
	BinarySearchTree* bst;
	int numberOfBuckets;
	unsigned int HashFunction(int key);
public:
	~HashTableBSTSeperateChaining();
	HashTableBSTSeperateChaining();
	void Insert(int key, int value) override;
	KeyValuePairBST Remove(int key);
	KeyValuePairBST* Get(int key);
	void PrintAll() const override;
	int GetSize() const override;
	bool IsEmpty() const override;
	void Clear() override;
};

