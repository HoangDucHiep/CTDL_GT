#ifndef _NODE_TYPE_
#define _NODE_TYPE_
#include <iostream>


template <class T>
class node
{
    public:
        T data;
        node *prev, *next;
        node(){}
        node(T d, node<T> *pre, node<T> *ne) : data(d), prev(pre), next(ne){};
        ~node(){}
};

#endif
