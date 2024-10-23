//
// Created by Abraham E. Orherhe on 22/10/2024.
//

#ifndef LINK_H
#define LINK_H

#include <iostream>

using namespace std;

template <class T>
class Link {
// private:
//     int data;
//     Link* next;

    T data;
public:
    Link *next;

    // void Display() const
    // {
    //     cout << this->data << "\n";
    // }

    explicit Link(const T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    [[nodiscard]] T GetData() const
    {
        return this->data;
    }
};



#endif //LINK_H
