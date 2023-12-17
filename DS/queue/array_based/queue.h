#ifndef __MY_QUEUE__
#define __MY_QUEUE__


template <class T>
class Queue
{

    private:
        int n, cap;
        int F, B;
        T *container;

    public:
        Queue()
        {
            n = cap = 0;
            F = B = 0;
            container = nullptr;
        }

        ~Queue()
        {
            delete []container;
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
            return container[F];
        }

        T& back() const
        {
            return container[(B ? B : cap)-1];        
        }

        // neu cap = 100, neu b chay den 101, B = 101 % 100 = vong ve 1;


        void push(T value)
        {
            if(n == cap)
            {
                T *temp = container;
                cap = cap*2+5;
                container = new T[cap];

                for(int i = F, j = 0; i < F+n; i++, j++)
                {
                    container[j] = temp[i%cap];
                }

                F = 0;
                B = n;
                delete[] temp;
            }

            container[B] = value;
            B = (B+1)%cap;
            n++;
        }

        void pop()
        {
            n--;
            F = (F+1)%cap;
        }
};



#endif