#include <iostream>
#include "LinkedList.h"

using namespace AEO;

int main()
{
    // Initialize a new linked list
    auto *list = new LinkedList<int>();
    auto *listCh = new LinkedList<char>();


    // Insert elements at the end
    list->Push(20);
    list->Push(25);

    // Insert element at the beginning
    list->Unshift(10);
    list->Unshift(5);


    // Insert element at a specific position
    list->Insert(15, 3);

    cout << "Linked list after insertions: \n";
    list->Display();

    // Delete element from the beginning
    list->Shift();
    cout << "Linked list after deleting from beginning: \n";
    list->Display();

    // Delete element from the end
    list->Shift();
    cout << "Linked list after deleting from end: \n";
    list->Display();

    // Delete element from a specific position
    list->Remove(2);
    cout << "Linked list after deleting from position 2: \n";
    list->Display();
    return 0;
}

