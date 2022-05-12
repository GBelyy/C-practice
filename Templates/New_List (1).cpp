#include <stdio.h>
#include <stdlib.h>

template <typename T>
struct List
{
private:
        typedef struct node Node;
    struct node 
    {
        T* val;
        struct node* next;
    };
        Node* head;
        size_t size;

public:

    List() : List(0)
    {
    }
   /* List(std::initializer_list<T> list)
    {
        size = list.size();
        Node* ptr = head;
        Node* id = list.begin();
        while (list.end())
        {
            Node* head = new Node;
            std::copy(list.begin(), list.begin()+1, Node->val);
            ptr = ptr->next;
        }
    }*/
    void push_front(T x)
    {

        Node* p_new_node = new Node;
        val = x;
        next = head;
        head = p_new_node;
        size++;
    }

    T& pop_front()
    {
        if (head == NULL)
        {
            std::cout << "Error! Can't remove an element. List is empty!\n";
            exit(1);
        }
        Node* temp = head;
        T result = temp->val;
        head = head->next;
        delete temp;
        size--;
        return result;
    }


    void insert_after(Node* p_node, Data x)
    {
        Node* p_new_node = new Node;
        p_new_node->val = x;
        p_new_node->next = p_node->next;
        p_node->next = p_new_node;
        size++;
    }

    T& erase_after(Node* p_node)
    {
        if (p_node == NULL || p_node->next == NULL)
            std::cout << "Error! Can't erase element from list\n";

        Node* temp = p_node->next;
        T temp_value = p_node->next->val;

        p_node->next = p_node->next->next;
        delete temp;
        size--;
        return temp_value;
    }


    void print() const
    {
        std::cout << "List: size =" << size <<", elements = { ";
        Node* ptr = head;
        while (ptr)
        {
            std::cout << ptr->val;
            ptr = ptr->next;
        }
        std::cout <<"\b\b }\n";
    }

    size_t get_size() const
    {
        return size;
    }
    iterator begin()
    {
        return head;
    }

    iterator end()
    {
        Node* ptr = head;
        while (ptr->next)
        {
            std::cout << ptr->val;
            ptr = ptr->next;
        }
        return ptr;
    }
     ~List() 
    {
        Node* ptr = head;
        Node* ptr_next;
        while (ptr != NULL)
        {
            ptr_next = ptr->next;
            delete ptr;
            ptr = ptr_next;
        }
        head = NULL;
    }
