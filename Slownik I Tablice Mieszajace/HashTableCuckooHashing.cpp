#include "HashTableCuckooHashing.h"
#include <iostream>

void HashTableCuckooHashing::Resize(int newCapacity)
{
	int oldCapacity = _capacity;
	_capacity = newCapacity;

	KeyValuePairCuckoo** oldHashTable = _hashTable;
	_hashTable = InitTable(_capacity);

	for (int i = 0; i < _numberOfTables; i++) {
		for (int j = 0; j < oldCapacity; j++) {
			if (oldHashTable[i][j].added) {
				Insert(oldHashTable[i][j].key, oldHashTable[i][j].value);
			}
		}
	}
	_cycleTreshhold = _capacity / 2;
}

unsigned int HashTableCuckooHashing::HashFunction(int key, int tableID)
{
	return tableID == 0 ? key % _capacity : (key / _capacity) % _capacity;
}

void HashTableCuckooHashing::Rehash(int key, int value)
{
	KeyValuePairCuckoo** oldArr = _hashTable;
	_hashTable = InitTable(_capacity);
	_size = 0;
	for (int i = 0; i < _numberOfTables; i++) {
		for (int j = 0; j < _capacity; j++) {
			if (oldArr[i][j].added) {
				Insert(oldArr[i][j].key, oldArr[i][j].value);
			}
		}
	}
	Insert(key, value);
}

KeyValuePairCuckoo** HashTableCuckooHashing::InitTable(int capacity)
{
	KeyValuePairCuckoo** arr = new KeyValuePairCuckoo * [capacity];

	for (int i = 0; i < _numberOfTables; i++) {
		arr[i] = new KeyValuePairCuckoo[capacity];
	}
	return arr;
}



HashTableCuckooHashing::~HashTableCuckooHashing()
{
	for (int i = 0; i < _numberOfTables; i++) {
		delete[] _hashTable[i];
	}
	delete [] _hashTable;
}

HashTableCuckooHashing::HashTableCuckooHashing()
{
	_size = 0;
	_capacity = 8;
	_cycleTreshhold = _capacity / 2;
	_hashTable = InitTable(_capacity);
}

void HashTableCuckooHashing::Insert(int key, int value)
{
	if (((float)_size / _capacity) / 2 >= _loadFactorTreshold)
	{
		Resize(_capacity * 2);
	}
	
	int count = 0;
	int tableID = 0;

	int currentKey = key;
	int currentValue = value;

	while (count <= _cycleTreshhold) {
		unsigned int index = HashFunction(currentKey, tableID);

		if (_hashTable[tableID][index].added && _hashTable[tableID][index].key == key) {
			_hashTable[tableID][index].value = value;
			return;
		}

		if (!_hashTable[tableID][index].added) {
			_hashTable[tableID][index] = KeyValuePairCuckoo(currentKey, currentValue);
			_size++;
			return;
		}

		int tempKey = _hashTable[tableID][index].key;
		int tempValue = _hashTable[tableID][index].value;

		_hashTable[tableID][index].key = currentKey;
		_hashTable[tableID][index].value = currentValue;
		currentKey = tempKey;
		currentValue = tempValue;

		tableID = (tableID + 1) % 2;
		count++;
	}
	Rehash(currentKey, currentValue);
}

KeyValuePairCuckoo HashTableCuckooHashing::Remove(int key)
{
	if (_capacity >= 8 && (float)_size / _capacity <= _loadFactorTreshold * 2)
	{
		Resize(_capacity / 2);
	}


	for (int i = 0; i < _numberOfTables; i++) {
		unsigned int pos = HashFunction(key, i);
		if (_hashTable[i][pos].key == key) {
			KeyValuePairCuckoo temp = _hashTable[i][pos];
			_hashTable[i][pos] = KeyValuePairCuckoo();
			return temp;
		}
	}
	std::cout << "Unable to find this key in hash table" << std::endl;
	_size--;
	return KeyValuePairCuckoo();
}

KeyValuePairCuckoo* HashTableCuckooHashing::Get(int key)
{
	for (int i = 0; i < _numberOfTables; i++) {
		unsigned int pos = HashFunction(key, i);
		if (_hashTable[i][pos].key == key) {
			KeyValuePairCuckoo* temp = &_hashTable[i][pos];
			return temp;
		}
	}
	std::cout << "Unable to find this key in hash table" << std::endl;
	return nullptr;
}

void HashTableCuckooHashing::PrintAll() const
{
	for (int i = 0; i < _numberOfTables; i++) {
		std::cout << "Table number " << i << "." << std::endl;
		for (int j = 0; j < _capacity; j++) {
			if (_hashTable[i][j].added)
				std::cout << j << ". KEY::" << _hashTable[i][j].key << ", VALUE::" << _hashTable[i][j].value << std::endl;
			else
				std::cout << j << ". NOT ADDED" << std::endl;
		}
	}
}

int HashTableCuckooHashing::GetSize() const
{
	return _size;
}

void HashTableCuckooHashing::Clear()
{
	for (int i = 0; i < _numberOfTables; i++) {
		delete[] _hashTable[i];
	}
	delete[] _hashTable;
	_size = 0;
	_capacity = 8;
	_hashTable = new KeyValuePairCuckoo * [_numberOfTables];
	for (int i = 0; i < _numberOfTables; i++) {
		_hashTable[i] = new KeyValuePairCuckoo[_capacity];
	}
}

bool HashTableCuckooHashing::IsEmpty() const
{
	return _size == 0;
}
