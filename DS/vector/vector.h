#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>
using namespace std;


        template <class T>
        class rev_it
        {
            private:
                T* cur;
        
            public:
            T* getCur()
            {
                return cur;
            }

            rev_it(T *c = nullptr)
            {
                cur = c;
            }

            rev_it& operator = (rev_it<T> ri)
            {
                cur = ri.cur;
            }

            T& operator * ()
            {
                return *cur;
            }

            rev_it<T> operator ++ ()
            {
                return --cur;
            }

            rev_it<T> operator ++ (int)
            {
                return cur--;
            }

            rev_it<T> operator + (int n)
            {
                return this->cur - n;
            }

            bool operator != (rev_it<T> ri) 
            {
                return cur != ri.getCur();
            }
        };

template<class T>
class Vector
{
    private:
        T* list;    //list of elements
        int n, cap;  //n - size, cap - capacity


        void expand(int newCap)         //use when need to expand the capacity
        {
            if(cap > newCap) return;    //if newCap is less than cap
            cap = newCap;
            T* temp = list;
            list = new T[cap];
            for(int i = 0; i < n; i++)
            {
                list[i] = temp[i];
            }
            if(temp) delete[] temp;
        }


    public:

        //iterator
        typedef T* iterator;
        iterator begin()
        {
            return list;
        }

        iterator end()
        {
            return list+n;
        }

        typedef rev_it<T> reverse_iterator;
        reverse_iterator r_begin()
        {
            return list+n-1;
        }
        reverse_iterator r_end()
        {
            return list-1;
        }
        

        Vector<T>& operator = (const Vector<T>& other)      //assign operator
        {
            n = other.n;
            cap = other.cap;
            
            if(this->list)
                delete [] this->list;
            
            if(cap > 0)
            {
                this->list = new T[n];
                for(int i = 0; i < n; i++)
                {
                    this->list[i] = other.list[i];
                }
            }
            else
                this->list = nullptr;
            
            return *this;           //this is a pointer, so *this is value, combine with Vector<T>&, function return a reference
        }     
        
        Vector()
        {
            n = cap = 0;
            list = nullptr;
        }
        Vector(int N, T val = 0)
        {
            n = cap = 0;
            list = nullptr;
            expand(N);
            n = N;
            for(int i = 0; i < n; i++)
            {
                list[i] = val;
            }
        }       
        Vector(const Vector& other)
        {
            *this = other;
        } //copy constructor
        ~Vector()
        {
            delete [] list;
        }

        int size() const
        {
            return n;
        }
        int capacity() const
        {
            return cap;
        }
        bool empty() const
        {
            return n == 0;
        }
        void resize(int newSize, T val = 0)         //update size (n), not cap
        {
            expand(newSize);
            for(int i = n; i < newSize; i++)
            {
                list[i] = val;
            }
            n = newSize;
        }
        void reserve(int newCap)        //update cap
        {
            expand(newCap);
        }

        T& operator [] (int index) const
        {
            return list[index];
        }
        T& at(int index) const      //same as []
        {
            return list[index];
        }
        T& back() const
        {
            return list[n - 1];
        }
        T& front() const
        {
            return list[0];
        }

        void push_back(T val)
        {
            if(n == cap)
                expand(cap*2 + 5);
            list[n++] = val;
        }
        void pop_back()
        {
            n--;
        }        
        void insert(iterator &it, T x)
        {
            if(n == cap)
            {
                int k = it - list;
                expand(cap*2 + 5);
                it = list + k;
            }

            for(iterator it2 = list + n - 1; it2 >= it; it2--)
            {
                *(it2 + 1) = *it2;
            }
            *(it++) = x;
            n++;
        }
        void erase(iterator it)
        {
            for(iterator it2 = it; it2 != end(); it2++)
            {
                *(it2) = *(it2 + 1);
            }
            n--;
        }
        void clear()    //delete all contents of vector
        {
            delete [] list;
            list = nullptr;
            n = cap = 0;
        }

};

#endif