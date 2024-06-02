#include "Dictionary.h"

Dictionary::Dictionary(HashTable* hashTable)
{
	_hashTable = hashTable;
}

Dictionary::~Dictionary()
{
	delete _hashTable;
}

void Dictionary::Insert(int key, int value)
{
	_hashTable->Insert(key, value);
}

void Dictionary::Remove(int key)
{
	
}

void Dictionary::Get(int key)
{

}

int Dictionary::GetSize()
{
	return _hashTable->GetSize();
}

bool Dictionary::isEmpty()
{
	return _hashTable->IsEmpty();
}

void Dictionary::PrintAll()
{
	_hashTable->PrintAll();
}
