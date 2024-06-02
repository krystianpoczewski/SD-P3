#pragma once
#include "HashTable.h"

class Dictionary
{
private:
	HashTable* _hashTable;


public:
	Dictionary(HashTable* hashTable);
	~Dictionary();

	void Insert(int key, int value);
	void Remove(int key);
	void Get(int key);


	int GetSize();
	bool isEmpty();
	void PrintAll();

};

