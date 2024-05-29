#pragma once
#include "HashTable.h"

//HASH TABLE WITH OPEN ADDRESSING AND LINEAR PROBING

class HashTableOpenAdressing : public HashTable
{
private:
	KeyValuePair* _dynamicArray;
	int _size, _capacity;
	const float _loadFactorTreshhold = 0.6;
	int QuardiaticProbing(int key);
	unsigned int HashFunction(int key, int probeCounter) override;
public:
	~HashTableOpenAdressing();
	HashTableOpenAdressing();
	void Insert(int key, int value) override;
	void Remove(int key) override;
	KeyValuePair Get(int key) override;
	void PrintAll() const override;
	int GetSize() const override;
	bool IsEmpty() const override;
	void Clear() override;
};

