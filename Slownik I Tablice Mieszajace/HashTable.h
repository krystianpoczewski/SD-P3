#pragma once

enum StateOfKeyValuePair {
	NOT_INITIALIZED,
	ADDED
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
		state = StateOfKeyValuePair::NOT_INITIALIZED;
	}
};

class HashTable
{
protected:
	virtual unsigned int HashFunction(int key, int probeCounter) = 0;
public:
	virtual ~HashTable() {}
	virtual void Insert(int key, int value) = 0;
	virtual void Remove(int key) = 0;
	virtual KeyValuePair Get(int key) = 0;
	virtual void PrintAll() const = 0;
	virtual int GetSize() const = 0;
	virtual void Clear() = 0;
	virtual bool IsEmpty() const = 0;
};

