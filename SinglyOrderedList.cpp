//
// Created by user.v2.0 on 18.02.2021.
//

#include "SinglyOrderedList.h"
#include <iostream>
// Поиск узла (адрес) с заданным значением
int SinglyOrderedList::searchNode(int item) {
    Node *x = head;
    int count = 0;
    while (x != nullptr) {
        if (x->item_ == item)
            return count;
        x = x->next_;
        count++;
    }
    return -1;
}


bool SinglyOrderedList::operator!=(const SinglyOrderedList &rhs) const {
    return !(rhs == *this);
}


SinglyOrderedList &SinglyOrderedList::operator=(const SinglyOrderedList &l1) {
    Node *current = l1.head;
    while (current != nullptr) {
        insertItem(current->item_);
        current = current->next_;
    }
    return *this;
} // удаление списка (левый операнд )
bool SinglyOrderedList::operator==(const SinglyOrderedList &rhs) const {
    Node *elem1 = this->head; // Left right
    Node *elem2 = rhs.head;
    while (elem1 != nullptr and elem1->item_ == elem2->item_) {
        elem1 = elem1->next_;
        elem2 = elem2->next_;
    }
    return (elem1 == nullptr);
}

SinglyOrderedList::SinglyOrderedList(const SinglyOrderedList &other) {
    this->count = other.count;
    this->head = new Node(other.head->item_);
    Node  *other_node = other.head , *this_node = this->head;
    for (int i = 0; i < other.count - 1; ++i) {
        this_node->next_ = new Node(other_node->next_->item_);
        other_node = other_node->next_;
        this_node = this_node->next_;
    }
}

void SinglyOrderedList::deleteItem(int item) {
    Node *node = head;
    if (node->item_ == item) {
        head = node->next_;
        delete node;
        count--;
        return;
    }
    for (int i = 0; i < count - 1; ++i) {
        if (item == (node->next_)->item_) {
            node->next_ = node->next_->next_;
            delete node->next_;
            count--;
            return;
        }
        node = node->next_;
    }

}

void SinglyOrderedList::insertItem(int item) {
    Node *node = head;
    if (head == nullptr){
        head = new Node(item);
        count++;
        return;
    }
    if (head->item_ > item) {
        head = new Node(item);
        head->next_ = node;
        count++;
        return;
    }
    for (int i = 0; i < count - 1; ++i) {
        if (node->next_->item_ > item) {
            Node *new_node = new Node(item);
            new_node->next_ = node->next_;
            node->next_ = new_node;
            count++;
            return;
        }
        node = node->next_;
    }
    Node *new_node = new Node(item);
    node->next_ = new_node;
    new_node->next_ = nullptr;
    count++;
}

int SinglyOrderedList::searchItem(int item) {
    return searchNode(item);
}

SinglyOrderedList::SinglyOrderedList(int element) {
    head->item_ = element;
    head->next_ = nullptr;
}

std::ostream &operator<<(std::ostream &os, const SinglyOrderedList &list) {
    SinglyOrderedList::Node *node = list.head;
    for (int i = 0; i < list.count; ++i) {
        os << node->item_ << " ";
        node = node->next_;
    }
    return os;
}

SinglyOrderedList SinglyOrderedList::unionLists(const SinglyOrderedList &other) {
    SinglyOrderedList result_list(*this);
    Node *node = other.head;
    for (int i = 0; i < other.count; ++i) {
        result_list.insertItem(node->item_);
        node = node->next_;
    }
    return result_list;
}

SinglyOrderedList SinglyOrderedList::differenceLists(const SinglyOrderedList &other) {
    SinglyOrderedList result_list(*this);
    Node *node = other.head;
    for (int i = 0; i < other.count; ++i) {
        if (result_list.searchItem(node->item_) != -1) {
            result_list.deleteItem(node->item_);
        }
        else {
            result_list.insertItem(node->item_);
        }
        node = node->next_;
    }
    return  result_list;
}

SinglyOrderedList SinglyOrderedList::intersectionLists(const SinglyOrderedList &other) {
    SinglyOrderedList result_list;
    Node *node = other.head;
    for (int i = 0; i < other.count; ++i) {
        if (this->searchItem(node->item_) != -1) {
            result_list.insertItem(node->item_);
        }
        node = node->next_;
    }
    return result_list;
}


