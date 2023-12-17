#ifndef __my_stack__
#define __my_stack__


template <class T>
class Stack
{
    private:
        int n, cap;
        T *elem;
    public:
        Stack()
        {
            n = cap = 0;
            elem = nullptr;
        }

        Stack(Stack const &other)
        {
            this = other;
        }

        ~Stack()
        {
            delete []elem;
        }

        Stack& operator = (Stack const &other)
        {
            n = other.n;
            cap = other.cap;
            elem = new T[cap];
            for(int i = 0; i < n; i++)
            {
                elem[i] = other.elem[i];
            }
            return *this;
        }

        int size()
        {
            return n;
        }

        T& top()
        {
            return elem[n-1];
        }

        bool empty()
        {
            return n==0;
        }

        void push(T value)
        {
            if(n==cap)
            {
                cap = cap ? cap*2+5 : 1;        //if cap = 0, cap = 1, else cap = cap*2 + 5
                T *temp = new T[cap];
                for(int i = 0; i < n; i++)
                {
                    temp[i] = elem[i];
                }

                delete []elem;
                elem = temp;
            }

            elem[n++] = value;
        }


        void pop()
        {
            n--;
        }

        void clear()
        {
            n=0;
        }
};


#endif