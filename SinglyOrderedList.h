//
// Created by user.v2.0 on 18.02.2021.
//
#pragma once
#ifndef SINGLYORDEREDLIST_SINGLYORDEREDLIST_H
#define SINGLYORDEREDLIST_SINGLYORDEREDLIST_H


#include <ostream>

class SinglyOrderedList {

private:
// Тип Node используется для описания элемента списка, связанного со
// следующим с помощью поля next_
    int count ;
    struct Node
    {
        int item_;
        Node *next_;
        Node (int item, Node *next = nullptr ):
                item_(item) , next_(next){ }
    };
    Node *head;
    int searchNode(int item);
public:
    SinglyOrderedList():count(0) ,head(nullptr){}
    SinglyOrderedList(int element) ;
    SinglyOrderedList(const SinglyOrderedList &other);
    void deleteItem(int item);
    void insertItem(int item);
    int searchItem(int item);
    bool operator==(const SinglyOrderedList &rhs) const;
    SinglyOrderedList unionLists(const SinglyOrderedList &other);
    SinglyOrderedList differenceLists(const SinglyOrderedList &other);
    SinglyOrderedList intersectionLists(const SinglyOrderedList &other);
    SinglyOrderedList& operator=(const SinglyOrderedList &rhs);

    bool operator!=(const SinglyOrderedList &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const SinglyOrderedList &list);
};


#endif //SINGLYORDEREDLIST_SINGLYORDEREDLIST_H
