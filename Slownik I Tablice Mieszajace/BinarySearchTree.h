#pragma once
#include "HashTable.h"
#include <iostream>

struct KeyValuePairBST {
	int key;
	int value;
	KeyValuePairBST() {}
	KeyValuePairBST(int key, int value) : key(key), value(value) {}
};

struct Node {
	KeyValuePairBST value;
	Node* leftChild;
	Node* rightChild;
	Node(KeyValuePairBST value) : value(value) {}
	Node(){ }
};

class BinarySearchTree
{
private:
	Node* root;
	int _size;
	Node* findMin(Node* node);
	Node* insertRecursivly(Node* node, KeyValuePairBST element);
	Node* removeRecursivly(Node* node, int key,Node& deletedNode, bool& found);
	Node* findRecursivly(Node* node, int key);
	void PrintElement(Node* node, std::string message) const;
	void ClearRecursivly(Node* node);
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Insert(int key, int value);
	Node Remove(int key);
	Node* Find(int key);
	bool isEmpty() const;
	int GetSize() const;
	void PrintAll() const;
	void Clear();
};

