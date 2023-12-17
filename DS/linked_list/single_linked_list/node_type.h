#ifndef _NODE_TYPE_
#define _NODE_TYPE_
#include <iostream>


template <class T>
class node
{
    public:
        T data;
        node *next;
        node(){}
        node(T d, node<T> *ne) : data(d), next(ne){};
};

#endif
