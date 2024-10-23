//
// Created by Abraham E. Orherhe on 22/10/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "Link.h"

namespace AEO
{
    template <class T>
    class LinkedList {
    public:
        Link<T> *head;
        int listSize;

        LinkedList()
        {
            head = nullptr;
            listSize = 0;
        }

        [[nodiscard]] bool IsEmpty() const
        {
            return this->head == nullptr;
        }

        // check if the list is empty.
        void CheckList() const
        {
            if (this->IsEmpty())
            {
                cout << "List is empty\n";
                return;
            }
        }

        void Display() const
        {
            const Link<T> *current = this->head;

            // check if the list is empty.
            cout << "List size: " << this->listSize << "\n";
            this->CheckList();

            while (current != nullptr)
            {
                // current->Display();
                cout << current->GetData() << " -> ";
                current = current->next;
            }

            cout << "\n";
        }

        // insert element at the beginning of the list.
        void Unshift (const T data)
        {
            auto *newLink = new Link<T>(data);

            if (this->IsEmpty()) {
                this->head = newLink;
                ++this->listSize;
                return;
            }

            Link<T> *current = this->head;
            newLink->next = current;
            this->head = newLink;
            ++this->listSize;
        }

        // remove element from the beginning of the list.
        T Shift()
        {
            this->CheckList();

            Link<T> *current = this->head;
            this->head = current->next;
            delete current;
            --this->listSize;
            return this->listSize;

        }

        // insert element at the end of the list.
        void Push (const T data)
        {
            auto *newLink = new Link(data);

            if (this->IsEmpty())
            {
                // newLink->next = nullptr;
                this->head = newLink;
                ++this->listSize;
                return;
            }

            Link<T> *temp = this->head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newLink;
            ++this->listSize;
        }

        // remove element from the end of the list.
        Link<T> *Pop()
        {
            this->CheckList();

            Link<T> *current = this->head;

            if (current->next == nullptr)
            {
                delete current;
                current = nullptr;
                --this->listSize;
                return current;
            }

            // Traverse to the second-to-last node
            while (current->next->next != nullptr)
            {
                current = current->next;
            }


            // Delete the last node
            delete current->next;

            // Set the second-to-last node's next to NULL
            current->next = nullptr;

            // decrement the list size.
            --this->listSize;

            // return the deleted node.
            return current;
        }

        // insert element at a specific position in the list.
        void Insert(const T data, int position)
        {
            if (position < 1)
            {
                cout << "Position should be >= 1. \n";
                return;
            }

            if (position == 1)
            {
                this->Unshift(data);
                return;
            }

            if (position > this->listSize)
            {
                cout << "Position out of range. \n";
                return;
            }

            auto *newLink = new Link<T>(data);
            Link<T> *temp = this->head;

            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }

            newLink->next = temp->next;
            temp->next = newLink;
            ++this->listSize;
        };

        // remove element from a specific position in the list.
        void Remove(int position)
        {
            if (position < 1)
            {
                cout << "Position should be >= 1. \n";
                return;
            }

            if (position == 1)
            {
                this->Shift();
                return;
            }

            if (position > this->listSize)
            {
                cout << "Position out of range. \n";
                return;
            }

            auto *temp = this->head;
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }

            // temporary node to hold the node to be deleted.
            const Link<T> *deletedNode = temp->next;

            // set the next node of the previous node to the next node of the node to be deleted.
            temp->next = temp->next->next;

            // delete the node.
            delete deletedNode;

            // decrement the list size.
            --this->listSize;
        }
    };

}




#endif //LINKEDLIST_H
