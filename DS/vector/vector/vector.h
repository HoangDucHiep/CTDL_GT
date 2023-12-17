#ifndef _MY_VECTOR_
#define _MY_VECTOR_
//---------------------------------------------------------//
#include <iostream>
#include "vector_iterator.h"
template <class T>
class VECTOR
{
    private:
        int length, cap;
        T *container;
    
    public:

    //----------------Capacity operations-------------------

        int size() const;
            //return vector size
        
        int capacity() const;
            //return vector capacity

        bool empty() const;
            //return true if the vector is empty

        void reserve(int newcap);
            //Requests that the vector capacity be at least enough to contain n elements.


    //--------------Element access operations---------------
        
        T& front() const;
            //Returns a reference to the first element in the vector

        T& back() const;
            //Returns a reference to the last element in the vector

        T& at(int n) const;
            //Returns a reference to the element at position ‘n’ in the vector
        
        T& operator[](int n);
            //Returns a reference to the element at position ‘n’ in the vector


    //----------------- Modifiers operations ---------------
        void pop_back();
            //pop or remove elements from a vector from the back.

        void push_back(T x);
            //push the elements into a vector from the back

        void insert(const int &size, const T &value);
            //inserts new elements before the element at the specified position

        void clear();
            //remove all elements
        
        VECTOR<T> &operator=(const VECTOR<T>& other);
            //copy operator 


    //--------------------Iterators------------------------
        typedef T* iterator;
        iterator begin();
        iterator end();

        typedef REVERSE_ITERATOR<T> reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();
        
    //Constructors
    VECTOR();                                       
            //default constructor
            //Constructs an empty container, with no elements.

        VECTOR(const int &size, const T &value);                    
            //fill constructor
            //Constructs a container with n elements. 
            //Each element is a copy of val (if provided).

        VECTOR(iterator start, iterator end);
            //range constructor
            //Constructs a container with as many elements as the range [first,last), 
            //with each element emplace-constructed from its 
            //corresponding element in that range, in the same order.
        VECTOR(reverse_iterator start, reverse_iterator end);
        


        VECTOR(VECTOR &other);
            //Constructs a container with a copy of each of the elements in x, in the same order.


        ~VECTOR(); 
            //Destructor
};

//definition

//constructor 
template <class T>
VECTOR<T>::VECTOR()
{
    length = cap = 0;
    container = NULL;
}

template <class T>
VECTOR<T>::VECTOR(const int &size, const T &value)
{
    length = cap = size;
    container = new T[cap];
    for(int i = 0; i < cap; i++)
    {
        container[i] = value;
    }
}

template <class T>
VECTOR<T>::VECTOR(VECTOR &other)
{
    *this = other;
}

template <class T>
VECTOR<T>::~VECTOR()
{
    if(length)
    {
        delete[] container;
    }
}

template <class T>
VECTOR<T>::VECTOR(iterator start, iterator end)
{
    length = cap = end - start;
    container = new T[cap];
    for (int i = 0; start != end; ++start, ++i) {
        container[i] = *start;
    }
}

template <class T>
VECTOR<T>::VECTOR(reverse_iterator start, reverse_iterator end)
{
    length = cap = start - end;
    container = new T[cap];
    for (int i = 0; start != end; ++start, ++i) {
        container[i] = *start;
    }
}


//Capacity operations

template <class T>
int VECTOR<T>::size() const
{
    return length;
}

template <class T>
int VECTOR<T>::capacity() const
{
    return cap;
}

template <class T>
bool VECTOR<T>::empty() const
{
    return length == 0;
}

template <class T>
void VECTOR<T>::reserve(int newCap)
{
    if(newCap < cap) return;
    //else
    cap = newCap;
    T *temp = new T[newCap];
    for(int i = 0; i < length; i++)
    {
        temp[i] = container[i];
    }

    if(container) delete[] container;
    container = temp;
}

//Element access operations
template <class T>
T& VECTOR<T>::front() const
{
    return container[0];
}

template <class T>
T& VECTOR<T>::back() const
{
    return container[length - 1];
}

template <class T>
T& VECTOR<T>::at(int n) const
{
    return container[n];
}

template <class T>
T& VECTOR<T>::operator[](int n)
{
    return container[n];
}


//Modifiers operations

template <class T>
void VECTOR<T>::pop_back()
{
    if(length > 0)
        length--;
}

template <class T>
void VECTOR<T>::push_back(T x)
{
    if(length >= cap)
    {
        reserve(cap*2 + 5);
    }
    container[length++] = x;
}

template <class T>
void VECTOR<T>::insert(const int &pos, const T &value)
{
    if(length == cap)
    {
        reserve(cap*2 + 5);
    }
    for(int i = length-1; i >= pos; i--)
    {
        container[i+1] = container[i];
    }
    container[pos] = value;
    length++;
}

template <class T>
void VECTOR<T>::clear()
{
    if(length)
    {
        delete[] container;
    }
    length = cap = 0;
}

template <class T>
VECTOR<T>& VECTOR<T>::operator=(const VECTOR<T>& other)
{
    if (this != &other)
    {
        this->length = other.length;
        this->cap = other.cap;

        if (this->container)
        {
            delete[] this->container;
        }

        if (cap > 0)
        {
            this->container = new T[this->length];
            for (int i = 0; i < this->length; i++)
            {
                this->container[i] = other.container[i];
            }
        }
        else
        {
            this->container = NULL;
        }
    }
    return *this;
}

template<class T>
typename VECTOR<T>::iterator VECTOR<T>::begin()
{
    return container;
}

template<class T>
typename VECTOR<T>::iterator VECTOR<T>::end()
{
    return container + length;
}

template<class T>
typename VECTOR<T>::reverse_iterator VECTOR<T>::rbegin()
{
    return container + length - 1;
}

template<class T>
typename VECTOR<T>::reverse_iterator VECTOR<T>::rend()
{
    return container - 1;
}

//---------------------------------------------------------//
#endif