#include <iostream>
#include "list.h"
#include <string>
using namespace std;







template<typename T>
List<T>::List()                                            //create node
{
    Size = 0;
    head = nullptr;
}


template<typename T>
List<T>::~List()
{
    clearr();
}
template<typename T>
void List<T>::print()
{
    Node<T>* Current = this->head;
    cout << "----Current List----Lenght = " << GetSize() << "\n";
    while (Current->pNext != NULL)
    {
        cout << Current->data << "\n";
        Current = Current->pNext;
    }
    cout << Current->data << "\n";
}

//delete first element
template<typename T>
void List<T>::popfront()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::pushback(const T& data)                            //add element
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }

    Size++;
}

template<typename T>
void List<T>::clearr()
{
    while (Size)
    {
        popfront();
    }
}

template<typename T>
inline void List<T>::pushfront(const T& data)
{
    head = new Node<T>(data, head);
    Size++;
}



template<typename T>
void List<T>::insert(const T& value)
{
    pushfront(value);
}

template<typename T>
bool List<T>::exists(const T& value) const
{
    if (Size == 0)
    {
        return false;
    }
    else
    {
        return head->exists(value);
    }
}


template<typename T>
void List<T>::remove(const T& value)
{
    if (exists(value))
    {
        if (Size == 0)
        {
            return;
        }
        Node<T>* element = head;
        if (head->getValue() == value)
        {
            Node<T>* temp = head->pNext;
            delete head;
            head = temp;
            Size--;
            return;
        }
        
        for (unsigned int i = 0; i < Size - 1; i++)
        {
            if (element->pNext->getValue() != value)
            {
                element = element->pNext;
                continue;
            }
            Node<T>* temp = element->pNext->pNext;
            delete element->pNext;
            element->pNext = temp;
            Size--;
            return;
        }
    }
}

