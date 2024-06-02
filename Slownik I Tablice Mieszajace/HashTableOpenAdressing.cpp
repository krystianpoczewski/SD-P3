#include "HashTableOpenAdressing.h"
#include <iostream>





unsigned int HashTableOpenAdressing::HashFunction(int key, int probeCounter) const
{
	if (key < 0)
		key *= -1;
	return (key + probeCounter * probeCounter + probeCounter) % _capacity;
}

void HashTableOpenAdressing::Resize(int newCapacity)
{
	int oldCapacity = _capacity;
	_capacity = newCapacity;
	KeyValuePair* newDynamicArray = new KeyValuePair[newCapacity];
	_size = 0;
	for (int i = 0; i < oldCapacity; ++i) {
		if (_dynamicArray[i].state == StateOfKeyValuePair::ADDED) {
			int probeCounter = 0;
			unsigned int hashValue = HashFunction(_dynamicArray[i].key, probeCounter);
			while (newDynamicArray[hashValue].state == StateOfKeyValuePair::ADDED) {
				hashValue = HashFunction(_dynamicArray[i].key, ++probeCounter);
			}
			newDynamicArray[hashValue] = _dynamicArray[i];
			_size++;
		}
	}
	delete[] _dynamicArray;
	_sizeWithTombstones = _size;
	_dynamicArray = newDynamicArray;
}

HashTableOpenAdressing::~HashTableOpenAdressing()
{
	delete[] _dynamicArray;
}

HashTableOpenAdressing::HashTableOpenAdressing()
{
	_size = 0;
	_sizeWithTombstones = 0;
	_capacity = 8;
	_dynamicArray = new KeyValuePair[_capacity];
}

void HashTableOpenAdressing::Insert(int key, int value)
{
	//RESIZING
	if ((float)_sizeWithTombstones / _capacity >= _loadFactorTreshhold) {
		Resize(_capacity * 3);
	}

	//INSERTING
	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);

	while (_dynamicArray[hashValue].state != StateOfKeyValuePair::NOT_INITIALIZED) {
		if (_dynamicArray[hashValue].key == key) {
			_dynamicArray[hashValue].value = value;
			return;
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	_dynamicArray[hashValue] = KeyValuePair(key, value);
	_size++;
	_sizeWithTombstones++;
}

void HashTableOpenAdressing::Remove(int key)
{
	if (_capacity > 8 && ((float)_sizeWithTombstones / _capacity) * 3 <= _loadFactorTreshhold) {
		Resize(_capacity / 3);
	}


	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);
	while (_dynamicArray[hashValue].state != StateOfKeyValuePair::NOT_INITIALIZED) {
		if (_dynamicArray[hashValue].state == StateOfKeyValuePair::ADDED && _dynamicArray[hashValue].key == key) {
			_dynamicArray[hashValue].state = StateOfKeyValuePair::DELETED;
			_size--;

			return;
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	std::cout << "Unable to find element with specified key" << std::endl;
}

KeyValuePair HashTableOpenAdressing::Get(int key)
{
	int probeCounter = 0;
	unsigned int hashValue = HashFunction(key, probeCounter);

	while (_dynamicArray[hashValue].state != StateOfKeyValuePair::NOT_INITIALIZED) {
		if (_dynamicArray[hashValue].state == StateOfKeyValuePair::ADDED && _dynamicArray[hashValue].key == key) {
			return _dynamicArray[hashValue];
		}
		hashValue = HashFunction(key, ++probeCounter);
	}

	throw std::invalid_argument("Unable to find a element with specified key");
}

void HashTableOpenAdressing::PrintAll() const
{
	for (int i = 0; i < _capacity; i++) {
		if (_dynamicArray[i].state != StateOfKeyValuePair::ADDED) {
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
	_sizeWithTombstones = 0;
	_capacity = 8;
	_dynamicArray = new KeyValuePair[_capacity];
}
