#ifndef _MY_NODE_
#define _MY_NODE_

template <class T>
class node
{
    public:
        int key;
        node<T> *parent, *right, *left;

        node(int k, node<T> *p = nullptr, node<T> *r = nullptr, node<T> *l = nullptr)
        {
            key = k;
            parent = p;
            right = r;
            left = l;
        }

        bool hasLeft() const
        {
            return left != nullptr;
        }

        bool hasRight() const
        {
            return right != nullptr;
        }

        node<T>* &getLeft()
        {
            return left;
        }

        node<T>* &getRight()
        {
            return right;
        }

        node<T>* &getParent()
        {
            return parent;
        }

        void setLeft(node<T>* p)
        {
            left = p;
        }

        void setRight(node<T>* p)
        {
            right = p;
        }

        void setParent(node<T>* p)
        {
            parent = p;
        }
};

#endif