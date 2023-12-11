#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>
using namespace std;

//size, empty, push_back, pop_back, back, front, [],  resize, insert, erase, iterator


template<class T>
class Vector
{
    private:
        T* list;    //list of elements
        int n, cap;  //n - size, cap - capacity


    public:
        //Constructor
        Vector();   //default constructor, construct an empty vector
        Vector(int n, T val);  //fill constructor, n elements (val)
        Vector(const Vector& other); //copy constructor


};


template<class T>
Vector<T>::Vector()
{
    n = cap = 0;
    list = nullptr;
}



#endif