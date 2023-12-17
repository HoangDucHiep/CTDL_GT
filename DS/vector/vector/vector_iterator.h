#ifndef _MY_REVERSE_ITERATOR_
#define _MY_REVERSE_ITERATOR_

#include <iostream>

template <class T>
class REVERSE_ITERATOR
{
    private:
        T *current;
    
    public: 
        REVERSE_ITERATOR(T *cur = NULL);
            //constructor

        REVERSE_ITERATOR(const REVERSE_ITERATOR<T>& other);
            //copy constructor

        REVERSE_ITERATOR<T>& operator = (const REVERSE_ITERATOR<T>& other);
            //overloaded = operator;

        REVERSE_ITERATOR<T> operator ++ ();
            //prefix increment operator
        
        REVERSE_ITERATOR<T> operator ++ (int);
            //postfix increment operator

        int operator - (REVERSE_ITERATOR<T> other);

        T& operator * ();
            //return value

        bool operator == (REVERSE_ITERATOR<T> other);
        bool operator!=(REVERSE_ITERATOR<T> other);

};


//definitions

template <class T>
REVERSE_ITERATOR<T>::REVERSE_ITERATOR(T *cur) : current(cur) {}

template <class T>
REVERSE_ITERATOR<T>::REVERSE_ITERATOR(const REVERSE_ITERATOR<T>& other)
{
    *this = other;
}

template <class T>
REVERSE_ITERATOR<T>& REVERSE_ITERATOR<T>::operator = (const REVERSE_ITERATOR<T>& other)
{
    this->current = other.current;
    return *this;
}


template <class T>
REVERSE_ITERATOR<T> REVERSE_ITERATOR<T>::operator ++ ()
{
    return REVERSE_ITERATOR<T>(--current);
}


template <class T>
REVERSE_ITERATOR<T> REVERSE_ITERATOR<T>::operator ++ (int)
{
    return REVERSE_ITERATOR<T>(current--);
}

template <class T>
bool REVERSE_ITERATOR<T>::operator == (REVERSE_ITERATOR<T> other){
    return current == other.current;
}

template <class T>
bool REVERSE_ITERATOR<T>::operator!=(REVERSE_ITERATOR<T> other){
    return current != other.current;
}

template <class T>
T& REVERSE_ITERATOR<T>::operator*()
{
    return *current;
}

template <class T>
int REVERSE_ITERATOR<T>::operator-(REVERSE_ITERATOR<T> other)
{
    return current - other.current;
}

#endif