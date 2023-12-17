#ifndef __MY_QUEUE__
#define __MY_QUEUE__


template <class T>
struct node
{
    T elem;
    node<T> *next;


    node(T e, node<T> *n = nullptr) 
    {
        elem = e;
        next = n;
    }
};


template <class T>
class Queue
{
    private:
        node<T>* Front;
        node<T>* Back;
        int n;  //size

    public:
        Queue()
        {
            Front = Back = nullptr;
            n = 0;
        }

        Queue(int m, T value = 0)
        {
            Front = Back = nullptr;
            n = 0;
            for(int i = 0; i < m; i++)
            {
                push(value);
            }
        }

        ~Queue()
        {
            while(n > 0)
            {
                pop();
            }
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
            return Front->elem;
        }

        T& back() const
        {
            return Back->elem;
        }

        void push(T value)
        {
            if(n == 0)
            {
                Front = Back = new node<T>(value);
            }
            else
            {
                Back = Back->next = new node<T>(value);
                //Back = Back->next;
            }
            n++;
        }

        void pop()
        {
            if(n==0)
            {
                cerr << "\nCan pop an empty queue!!";
            }
            else if(n == 1)
            {
                delete Front;
                Front = Back = nullptr;
                n--;
            }
            else
            {
                node<T> *temp = Front;
                Front = Front->next;
                delete temp;
                n--;
            }
        }

};


#endif