#ifndef _MY_S_LIST_
#define _MY_S_LIST_
#include <iostream>

#include "node_type.h"
#include "linked_list_iterator.h"

template <class T>
class LIST
{
    private:
        unsigned int n;  //size
        node<T> *head, *tail;
        void deleteList()
        {
            while(!empty()) pop_back();
        }

    public:

    /*---------------------- Iterator ---------------------- */
        typedef ITERATOR<T> iterator;
        iterator begin()
        {
            return head;
        }
        iterator end()
        {
            return NULL;
        }

    /* ----------Destructor, Assign op, Constructor------------ */

        ~LIST();

        LIST<T>& operator = (LIST<T> &other);

        LIST();
            //empty container constructor (default constructor)
            //Constructs an empty container, with no elements.  
            
        LIST(int N, T value);
            // fill constructor
            //Constructs a container with n elements. 
            //Each element is a copy of val (if provided).

        LIST(iterator first, iterator last);
            //range constructor
            //Constructs a container with as many elements as the range [first,last), 
            //with each element emplace-constructed from its corresponding 
            //element in that range, in the same order.

        LIST(LIST<T>& other);
            //copy constructor (and copying with allocator)
            //Constructs a container with a copy of each of 
            //the elements in x, in the same order.




    /* -------------------Capacity operators------------------ */
        bool empty() const;
            //return true if the list is empty
            
        unsigned int size() const;
            //return list's size
        


    /* -------------------Element access operators------------------ */

        T& front() const;
            //Access first element

        T& back() const;
            //Access last element

    
    /* ------------------Modifiers operators---------------- */

        void push_back(const T& value);
        void push_front(const T& value);
        void insert(iterator it, const T& value);
        void pop_front();
        void pop_back();
        void erase(iterator it);
};   



template <class T>
LIST<T>& LIST<T>::operator = (LIST<T> &other)
{
    if(this != &other)
    {
        deleteList();
        iterator it = other.begin();
        while(it != other.end())
        {
            this->push_back(it.get()->data);
            it++;
        }
    }
    return *this;
}

template <class T>
LIST<T>::~LIST()
{
    deleteList();
}

template <class T>
LIST<T>::LIST()
{
    n = 0;
    head = tail = NULL;
}

template <class T>
LIST<T>::LIST(int N, T value){
    head = tail = NULL;
    n = 0;
    while(N--)
    {
        push_back(value);
    }
}

template <class T>
LIST<T>::LIST(iterator first, iterator last)
{
    head = tail = NULL;
    n = 0;
    while(first != last)
    {
        push_back(first.get()->data);
        first++;
    }
}

template <class T>
LIST<T>::LIST(LIST<T>& other)
{
    head = tail = NULL;
    n = 0;
    node<T> *p = other.head;
    while(p != NULL)
    {
        this->push_back(p->data);
        p = p->next;
    }
}



template <class T>
bool LIST<T>::empty() const
{
    return n==0;
}

template <class T>
unsigned int LIST<T>::size() const
{
    return n;
}



template <class T>
T& LIST<T>::front() const
{
    return head->data;
}

template <class T>
T& LIST<T>::back() const
{
    return tail->data;
}



template <class T>
void LIST<T>::push_front(const T& value)
{
    node<T> *newNode = new node<T>(value, NULL, head);
    if (n == 0) {
        tail = newNode;
    } else {
        head->prev = newNode;
    }

    head = newNode;
    n++;
}

template <class T>
void LIST<T>::push_back(const T& value)
{
    node<T>* newNode = new node<T>;
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = NULL;
    if (n == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    n++;
}


template <class T>
void LIST<T>::pop_front()
{
    if(n == 0)
    {
        return;
    }

    if(n == 1)
    {
        delete head;
        head = tail = NULL;
    }
    else{
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    
    n--;
}

template <class T>
void LIST<T>::pop_back()
{
    if(n == 0)
    {
        return;
    }

    if(n == 1)
    {
        delete head;
        head = tail = NULL;
        n--;
        return;
    }

    node<T> *temp = tail;
    tail = tail->prev;
    delete temp;
    tail->next = NULL;
    n--;
}

template <class T>
void LIST<T>::insert(iterator it, const T& value)
{
    {
        node<T> *newNode = new node<T>;
        newNode->data = value;
        newNode->next = it.getNext();
        it.getNext()->prev = newNode;
        newNode->prev = it.get();
        it.get()->next = newNode;
    }
    n++;
}

template <class T>
void LIST<T>::erase(iterator it)
{
    if (it == end()) {
        return;
    }
    if (it == begin()) {
        pop_front();
    } 
    else {
        node<T> *temp = it.get();
        it.getNext()->prev = it.getPrev();
        it.getPrev()->next = it.getNext();
        delete temp;
    }
    n--;
}


#endif