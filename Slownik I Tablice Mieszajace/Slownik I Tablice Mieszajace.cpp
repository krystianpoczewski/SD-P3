#include <iostream>
#include "Dictionary.h"
#include "HashTable.h"
#include "HashTableOpenAdressing.h"
#include "BinarySearchTree.h"
#include "HashTableBSTSeperateChaining.h"
#include "HashTableCuckooHashing.h"


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
    ht.Insert(400, 11);
    ht.Insert(600, 11);
    ht.Insert(70000, 11);
    ht.PrintAll();

    ht.Get(10);

    ht.Remove(20);
    ht.Remove(3);
    ht.Remove(2);
    ht.Remove(1);
    ht.Remove(10);
    ht.Remove(18);
    ht.Remove(0);
    ht.Insert(6, 11);
    ht.Insert(8, 11);
    ht.PrintAll();

    BinarySearchTree bst;
    bst.Insert(12,33);
    bst.Insert(22,44);
    bst.Insert(33,55);
    bst.Insert(1,55);
    bst.Insert(5,55);
    bst.Insert(4,55);
    bst.Insert(444,55);
    bst.PrintAll();
    Node* n = bst.Find(444);
    std::cout << n->value.GetKey() << " " << n->value.GetValue() << std::endl;
    Node nd = bst.Remove(4);
    std::cout << nd.value.GetKey() << " " << nd.value.GetValue() << std::endl;
    bst.PrintAll();

    BinarySearchTree htbts;
    htbts.Insert(12, 12);
    htbts.Remove(12);
    htbts.Insert(111, 22);
    htbts.Insert(11, 11);
    htbts.Insert(9, 11);
    htbts.Insert(22, 11);
    htbts.Insert(76, 11);
    htbts.Insert(1251, 11);
    htbts.Remove(12);
    htbts.PrintAll();



    HashTableCuckooHashing htc;
    htc.PrintAll();
    htc.Insert(2, 15);
    htc.Insert(10, 15);
    //htc.Remove(2);
    htc.PrintAll();
    htc.Insert(3, 22);
    htc.Insert(10, 151);
    htc.Insert(18, 1);
    htc.Insert(1, 11);
    htc.Insert(0, 11);
    htc.Insert(4, 11);
    htc.Insert(5, 11);
    htc.Insert(618, 11);
    htc.Insert(20, 11);
    htc.Insert(400, 11);
    htc.Insert(600, 11);
    htc.Insert(70000, 11);
    htc.PrintAll();

    htc.Get(10);

    
    //ht.PrintAll();
}

