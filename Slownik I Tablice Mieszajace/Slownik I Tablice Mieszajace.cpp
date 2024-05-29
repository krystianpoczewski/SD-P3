#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"
#include "HashTableOpenAdressing.h"

int main()
{
    HashTableOpenAdressing ht;
    ht.PrintAll();
    ht.Insert(2, 15);
    ht.Insert(3, 22);
    ht.Insert(10, 151);
    ht.Insert(18, 1);
    ht.Insert(1, 11);
    ht.Insert(0, 11);
    ht.Insert(4, 11);
    ht.Insert(5, 11);
    ht.Insert(618, 11);
    ht.Insert(20, 11);
    ht.PrintAll();

    ht.Get(10);

    ht.Remove(20);
    ht.Remove(3);
    ht.Remove(2);
    ht.Remove(1);
    ht.Remove(10);
    ht.Remove(18);
    ht.Remove(0);
    ht.PrintAll();
}

