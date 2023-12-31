#ifndef __my_llist__
#define __my_llist__

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class node
{
    public:
        T value;
        node* next;

        node(T v, node<T>*n = nullptr) {value = v; next = n;}
};


template <class T>
struct iter
{
    node<T> *cur;
    iter(node<T>* c = nullptr) 
    {
        cur = c;
    }

    iter(const iter &other)
    {
        cur = other.cur;
    }

    T &operator*()
    {
        return cur->value;
    }

    iter<T> operator++()
    {
        cur = cur->next;
        return cur;
    }
    iter<T> operator++(int)
    {
        node<T> *temp = cur;
        cur = cur->next;
        return temp;
    }
    bool operator!=(iter<T> it)
    {
        return cur != it.cur;
    }
    iter<T> &operator=(iter<T> it)
    {
        cur = it.cur;
        return *this;
    }
    iter<T> operator + (int n)
    {
        iter<T> temp(*this);
        while(n--){
            temp.cur = temp.cur->next;
        }
        return temp;
    }

};


template <class T>
class List
{
    private:
        int n; //size
        node<T> *head, *tail;

    public:

        //iterators
        typedef iter<T> iterator;

        iterator begin()
        {
            return head;
        }
        iterator end()
        {
            return nullptr;
        }

        List()
        {
            n = 0;
            head = tail = nullptr;
        }

        List(int k, T v = 0)
        {
            n = 0;
            head = tail = nullptr;
            while(k--)
            {
                push_front(v);
            }
        }

        ~List()
        {
            clear();
        }

        bool empty() const
        {
            return n == 0;
        }

        int size() const
        {
            return n;
        }

        T& front() const
        {
            return head->value;
        }
        T& back() const
        {
            return tail->value;
        }

        void push_back(T value)
        {
            if(n==0)    //neu rong, push_front
            {
                push_front(value);
            }
            else
            {
                node<T> *newNode = new node<T>(value);      //tao node moi
                tail = tail->next = newNode;    //cho node moi vao cuoi, tail tro toi node moi
                n++;
            }
        }
        void push_front(T value)
        {
            head = new node<T>(value, head);        //tao node moi, next tro toi head, head tro toi node moi
            if(n == 0)     //neu rong, tail va head cung vi tri 
            {
                tail = head;
            }
            n++;
        }

        void pop_back()         //if there is just 1 elem, delete the node, set head and tail.
        {
            if(n==1) {delete head; head=tail=nullptr;}
            else
            {
                node<T>*p=head;             //pointer for loop
                while(p->next!=tail) p=p->next;         //loop until the node right before tail
                delete tail;        //delete tail
                tail=p;     //tail points to p
                tail->next=nullptr;     //set null for next
            }
            n--;
        }


        void pop_front()
        {
            node<T> *temp = head;       
            head = head->next;
            delete temp;
            n--;
            if(n==0) tail = nullptr;
        }

        template <class K = less<T>>
        void sort(K cmp = less<T>())        //bubble sort
        {
            for(node<T>* p = head; p != tail; p = p->next)
            {
                for(node<T>* q = p->next; q != nullptr; q = q->next)
                {
                    if(cmp(q->value, p->value))
                    {
                        swap(p->value, q->value);
                    }
                }
            }
        }

        void insert(iterator it, T value)   //insert.png
        {
            node<T> *temp = it.cur;
            temp->next = new node<T>(temp->value, temp->next);      
            temp->value = value;
            n++;
        }


        void erase(iterator it)     //erase.png
        {
            if(it.cur==head) return pop_front();
            if(it.cur==tail) return pop_back();
            node<T>*p=head,*q=it.cur;       
            while(p->next!=q) p=p->next;    //loop until the node next to iterator
            p->next=q->next;    
            delete q;
            n--;
        }

        void clear()
        {
            while(n != 0) pop_front();
        }
};


#endif