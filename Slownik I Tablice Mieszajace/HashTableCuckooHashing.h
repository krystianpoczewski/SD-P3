#pragma once
#include "HashTable.h"
#include "KeyValuePair.h"


class HashTableCuckooHashing : public HashTable
{
private:
	int _size;
	int _capacity;
	const float _loadFactorTreshold = 0.5;
	int _cycleTreshhold;
	const int _numberOfTables = 2;
	KeyValuePairCuckoo** _hashTable;
	void Resize(int newCapacity);
	unsigned int HashFunction(int key, int tableID);
	void Rehash(int key, int value);
	KeyValuePairCuckoo** InitTable(int newCapacity);

public:
	~HashTableCuckooHashing();
	HashTableCuckooHashing();
	void Insert(int key, int value) override;
	KeyValuePair Remove(int key);
	KeyValuePair* Get(int key);
	void PrintAll() const override;
	int GetSize() const override;
	void Clear() override;
	bool IsEmpty() const override;
};

