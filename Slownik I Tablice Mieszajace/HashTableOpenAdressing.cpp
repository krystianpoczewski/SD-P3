#include "HashTableOpenAdressing.h"
#include <iostream>



int HashTableOpenAdressing::QuadraticProbing(int key)
{
	return (key) % _capacity;
}

unsigned int HashTableOpenAdressing::HashFunction(int key, int probeCounter)
{
	if (key < 0)
		key *= -1;
	return (QuadraticProbing(key) + probeCounter * probeCounter + probeCounter) % _capacity;
}

HashTableOpenAdressing::~HashTableOpenAdressing()
{
	delete[] _dynamicArray;
}

HashTableOpenAdressing::HashTableOpenAdressing()
{
	_size = 0;
	_capacity = 8;
	_dynamicArray = new KeyValuePair[_capacity];
}

void HashTableOpenAdressing::Insert(int key, int value)
{
	//RESIZING
	if ((float)_size / _capacity >= _loadFactorTreshhold) {
		int oldCapacity = _capacity;
		_capacity *= 3;
		KeyValuePair* newDynamicArray = new KeyValuePair[_capacity];

		for (int i = 0; i < oldCapacity; ++i) {
			if (_dynamicArray[i].state == StateOfKeyValuePair::ADDED) {
				int probeCounter = 0;
				unsigned int hashValue = HashFunction(_dynamicArray[i].key, probeCounter);
				while (newDynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
					hashValue = HashFunction(_dynamicArray[i].key, ++probeCounter);
				}
				newDynamicArray[hashValue] = _dynamicArray[i];
			}
		}
		delete[] _dynamicArray;
		_dynamicArray = newDynamicArray;
	}

	//INSERTING
	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);

	while (_dynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
		if (_dynamicArray[hashValue].key == key) {
			_dynamicArray[hashValue].value = value;
			return;
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	KeyValuePair elementToInsert(key, value);
	_dynamicArray[hashValue] = elementToInsert;
	_dynamicArray[hashValue].state = StateOfKeyValuePair::ADDED;
	_size++;
}

void HashTableOpenAdressing::Remove(int key)
{
	if (((float)_size / _capacity) * 3 <= _loadFactorTreshhold) {
		int oldCapacity = _capacity;
		_capacity /= 3;
		KeyValuePair* newDynamicArray = new KeyValuePair[_capacity];

		for (int i = 0; i < oldCapacity; ++i) {
			if (_dynamicArray[i].state == StateOfKeyValuePair::ADDED) {
				int probeCounter = 0;
				unsigned int hashValue = HashFunction(_dynamicArray[i].key, probeCounter);
				while (newDynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
					hashValue = HashFunction(_dynamicArray[i].key, ++probeCounter);
				}
				newDynamicArray[hashValue] = _dynamicArray[i];
			}
		}
		delete[] _dynamicArray;
		_dynamicArray = newDynamicArray;
	}


	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);
	while (_dynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
		if (_dynamicArray[hashValue].key == key) {
			_dynamicArray[hashValue] = KeyValuePair();
			_size--;
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	std::cout << "Unable to find element with specified key" << std::endl;
}

KeyValuePair HashTableOpenAdressing::Get(int key)
{
	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);

	while (_dynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
		if (_dynamicArray[hashValue].key == key) {
			return _dynamicArray[hashValue];
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	throw std::invalid_argument("Unable to find a element with specified key");
}

void HashTableOpenAdressing::PrintAll() const
{
	for (int i = 0; i < _capacity; i++) {
		if (_dynamicArray[i].state == StateOfKeyValuePair::NOT_INITIALIZED) {
			std::cout << i << ". NO VALUE" << std::endl;
		}
		else {
			std::cout << i << ". Key :: " << _dynamicArray[i].key << ", Value :: " << _dynamicArray[i].value << std::endl;
		}
	}
}

int HashTableOpenAdressing::GetSize() const
{
	return _size;
}

bool HashTableOpenAdressing::IsEmpty() const
{
	return _size == 0;
}

void HashTableOpenAdressing::Clear()
{
	delete[] _dynamicArray;
	_size = 0;
	_capacity = 8;
	_dynamicArray = new KeyValuePair[_capacity];
}
