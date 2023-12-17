#ifndef _LINKED_LIST_ITE_
#define _LINKED_LIST_ITE_
#include "node_type.h"

    template<class T>
    class ITERATOR
    {
        private:
            node<T>* cur;

        public:
            ITERATOR()
            {
                cur = NULL;
            }

            ITERATOR(node<T> *p)
            {
                cur = p;
            }

            ITERATOR<T> &operator = (ITERATOR<T> other)
            {
                this->cur = other.cur;
                return *this;
            }

            T& operator * ()
            {
                return cur->data;
            }

            ITERATOR<T> operator ++ ()
            {
                cur = cur->next;
                return ITERATOR(cur);
            }


            ITERATOR<T> operator + (int n)
            {
                ITERATOR<T> temp(*this);
                while(n--){
                    temp.cur = temp.cur->next;
                }
                return temp;
            }


            ITERATOR<T> operator ++ (int)
            {
                ITERATOR temp = *this;
                this->cur = this->cur->next;
                return ITERATOR(temp);
            }

            bool operator == (ITERATOR other)
            {
                return this->cur == other.cur;
            }

            bool operator != (ITERATOR other)
            {
                return this->cur != other.cur;
            }

            node<T>* getNext()
            {
                return cur->next;
            }

            node<T> *get()
            {
                return cur;
            }
    };

#endif