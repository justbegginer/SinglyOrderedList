#include <iostream>
#include "SinglyOrderedList.h"
int main() {
    SinglyOrderedList list ;
    list.insertItem(2); // Добавление элементов
    list.insertItem(3);
    list.insertItem(1);
    SinglyOrderedList list1(list);
    std::cout << list1 << "\n"; // Печать элементов
    std::cout << ( (list.searchItem(1) != -1) ? "1 find " : "1 not find")<< std::endl; //должен найти
    std::cout << ( (list.searchItem(8) != -1) ? "8 find " : "8 not find ")<< std::endl; //не должен
    list.deleteItem(1);
    std::cout << ( (list.searchItem(1) != -1) ? "1 find " : "1 not find ")<< std::endl;//не должен
    list.insertItem(0);
    std::cout << list << "\n";
    SinglyOrderedList list2 = list.unionLists(list1), list3 = list.differenceLists(list1) , list4 = list.intersectionLists(list1);
    std::cout << list2 << "\n";
    std::cout << list3 << "\n";
    std::cout << list4 << "\n";
    return 0;
}
