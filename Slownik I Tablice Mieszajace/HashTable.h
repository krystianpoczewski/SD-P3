#pragma once

struct KeyValuePair {
	int key;
	int value;
	KeyValuePair();
	KeyValuePair(int key, int value) {
		this->key = key;
		this->value = value;
	}
};

class HashTable
{
protected:
	virtual unsigned int HashFunction(int key) = 0;
public:
	virtual ~HashTable() {}
	virtual void Insert(int key, int value) = 0;
	virtual void Remove(int key) = 0;
	virtual KeyValuePair Get(int key) = 0;
	virtual void PrintAll() const = 0;
	virtual int GetSize() const = 0;
	virtual void Clear() = 0;
};

