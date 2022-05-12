#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include "container.h"
#include <algorithm>
#include <stdexcept>
#include <vector>
using namespace std;


template<typename T>
class Node
{
public:

    Node<T>* pNext;                                      //pointer Next
    T data;
    bool exists(const T& data);
    T getValue() const;
    Node(const T& data, Node<T>* pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};
template<typename T>
T Node<T>::getValue() const
{
    return data;
}
template<typename T>
bool Node<T>::exists(const T& data)
{
    Node<T>* current = this;
    while (current)
    {
        if (current->data == data)
        {
            return true;
        }
        current = current->pNext;
    }
    return false;
}
template class Node<int>;
template class Node<std::string>;

template<typename T>
class List :public Container<T>

{
public:
    List();
    ~List();
    
    void popfront();
    void pushback(const T& data);
    void clearr();
    void pushfront(const T& data);

    void insert(const T& value) ;
    void remove(const T& index);
    int GetSize() { return Size; }
    bool exists(const T& data) const ;
    void print();

private:
    unsigned int Size;
    Node<T>* head;
};

template class List<int>;
template class List<std::string>;


#endif // LIST_H