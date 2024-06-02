#pragma once
#include "HashTable.h"

//HASH TABLE WITH OPEN ADDRESSING AND LINEAR PROBING

enum StateOfKeyValuePair {
	NOT_INITIALIZED,
	ADDED,
	DELETED
};

struct KeyValuePair {
	int key;
	int value;
	StateOfKeyValuePair state = StateOfKeyValuePair::NOT_INITIALIZED;
	KeyValuePair() {
		state = StateOfKeyValuePair::NOT_INITIALIZED;
	}
	KeyValuePair(int key, int value) {
		this->key = key;
		this->value = value;
		state = StateOfKeyValuePair::ADDED;
	}
};

class HashTableOpenAdressing : public HashTable
{
private:
	KeyValuePair* _dynamicArray;
	int _size, _capacity, _sizeWithTombstones;
	const float _loadFactorTreshhold = 0.6;
	unsigned int HashFunction(int key, int probeCounter) const;
	void Resize(int newCapacity);
public:
	~HashTableOpenAdressing();
	HashTableOpenAdressing();
	void Insert(int key, int value) override;
	void Remove(int key);
	KeyValuePair Get(int key);
	void PrintAll() const override;
	int GetSize() const override;
	bool IsEmpty() const override;
	void Clear() override;
};

