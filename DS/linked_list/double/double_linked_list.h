#ifndef __my_dlist__
#define __my_dlist__

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class node
{
    public:
        T value;
        node *prev, *next;

        node(T v, node *p = nullptr, node *n = nullptr)
        {
            value = v;
            prev = p;
            next = n;
        }


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
struct rev_it
{
    node<T> *cur;
    rev_it(node<T>* c = nullptr) 
    {
        cur = c;
    }

    rev_it(const rev_it &other)
    {
        cur = other.cur;
    }

    T &operator*()
    {
        return cur->value;
    }

    rev_it<T> operator++()
    {
        cur = cur->prev;
        return cur;
    }
    rev_it<T> operator++(int)
    {
        node<T> *temp = cur;
        cur = cur->prev;
        return temp;
    }
    bool operator!=(rev_it<T> it)
    {
        return cur != it.cur;
    }
    rev_it<T> &operator=(rev_it<T> it)
    {
        cur = it.cur;
        return *this;
    }
    rev_it<T> operator + (int n)
    {
        rev_it<T> temp(*this);
        while(n--){
            temp.cur = temp.cur->prev;
        }
        return temp;
    }

};




template <class T>
class List
{
    private:
        node<T> *head, *tail;
        int n;  //size

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


        typedef rev_it<T> reverse_iterator;
        reverse_iterator r_begin()
        {
            return tail;
        }

        reverse_iterator r_end()
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
                push_front();
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
            if(n==0)
                return push_front(value);
            tail = tail->next = new node<T>(value, tail, nullptr);
            n++;
        }

        void push_front(T value)
        {
            if(n==0)
            {
                head = tail = new node<T>(value);
            }
            else
            {
                head = new node<T>(value, nullptr, head);
                head->next->prev = head;
                
            }
            n++;
        }

        void pop_back()
        {
            if(n==1)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                node<T> *temp =  tail;
                tail = tail->prev;
                delete temp;
                tail->next = nullptr;
            }
            n--;
        }

        void pop_front()
        {
            if(n==1)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            { 
                node<T> *temp = head;
                head = head->next;
                delete temp;
                head->prev = nullptr;
            }
            n--;
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

        void traverse()
        {
            for(node<T>* p = head; p != nullptr; p = p->next)
            {
                cout << p->value << " ";
            }
        }

        void insert(iterator it, T value)
        {
            if(it.cur == head) return push_front(value);
            node<T> *p = it.cur->prev;
            p->next = new node<T>(value, p, it.cur);
            it.cur->prev = p->next;
            n++;
        }

        void erase(iterator it)
        {
            if(it.cur == head) return pop_front();
            if(it.cur == tail) return pop_back();

            node<T> *temp = it.cur->prev, *temp2 = it.cur->next;
            delete it.cur;

            temp->next = temp2;
            temp2->prev = temp;
            n--;
        }

        void clear()
        {
            while(n)
            {
                pop_front();
            }
        }

};


#endif