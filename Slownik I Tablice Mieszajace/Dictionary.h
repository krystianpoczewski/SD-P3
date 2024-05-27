#pragma once
class Dictionary
{
public:
	Dictionary();
	~Dictionary();

	void Insert(int key, int value);
	void Remove(int key);
	void Get(int key);
	bool Exists(int key);


	int GetSize();
	bool isEmpty();
	void PrintAll();

	void Keys();
	void Values();
};

