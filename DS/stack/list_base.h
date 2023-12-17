#ifndef __my_stack__
#define __my_stack__

#include <iostream>
using namespace std;

template <class T>
struct node
{
    public:
        T value;
        node *next;

        node(T v, node<T> *n = nullptr)
        {
            this->value = v;
            this->next = n;
        }
};

template <class T>
class Stack
{
    private:
        node<T> *head;
        int n;  //size

    public:

        Stack()
        {
            n = 0;
            head = NULL;
        }

        ~Stack() 
        {
            while(true)
            {
                if(head == nullptr)
                {
                    exit(EXIT_SUCCESS);
                }
                node<T>* temp = head;
                head = temp->next;
                temp->next = nullptr;
                delete temp;
            }
            
        }

        int size() {return n;}
        T& top()
        {
            return head->value;
        }

        bool empty() {return n==0;}

        void push(T value)
        {
            node<T> *new_node = new node<T>(value);
            if(!new_node)
            {
                cerr << "\nOverflow!!";
                exit(EXIT_FAILURE);
            }
            new_node->next = head;
            head = new_node;
            n++;
        }
        void pop() {
            if(head == nullptr)
            {
                cerr << "\nUnderflow!!";
                exit(EXIT_FAILURE);
            }
            node<T>* temp = head;
            head = temp->next;
            temp->next = nullptr;
            delete temp;
            n--;
        }
        void clear()
        {
            
        }

};


#endif