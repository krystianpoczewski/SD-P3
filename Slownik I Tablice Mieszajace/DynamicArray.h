#pragma once
#include "HashTable.h"
#include "HashTableOpenAdressing.h"

class DynamicArray
{
private:
	int _capacity;
	KeyValuePair* _dynamic_array;
	int _size;
public:
	DynamicArray();
	~DynamicArray();
	void IncreaseCapacity();
	void DecreaseCapacity();
	void InsertAt(int index, KeyValuePair element);
	void DeleteAt(int index);
	int GetSize() const;
	int GetCapacity() const;
	bool IsEmpty() const;
	void Clear();
	KeyValuePair& GetAt(int index);
	void PrintAll();
};

