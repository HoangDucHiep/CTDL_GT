#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include "binary_tree.h"

template <class T>
class binary_search_tree : public binary_tree<T>
{
    private:
        node<T>* searchFromTree(node<T>* &p, const T &searchItem);

        node<T>* insertToTree(node<T>* &p, const T &insertItem);

        void deleteFromTree(node<T>* &p, const T &deleteItem);


        node<T>* getMin(node<T>* &p);
        node<T>* getMax(node<T>* &p);
        node<T>* getSuccessor(node<T>* &p);
        

    public:

        node<T>* search(const T &searchItem);

        node<T>* insert(const T &insertItem);

        void delete_node(const T &deleteItem);

};


template <class T>
node<T>* binary_search_tree<T>::getMin(node<T>* &p)
{
    if(p->left == nullptr)
        return p;
    getMin(p->left);
}

template <class T>
node<T>* binary_search_tree<T>::getMax(node<T>* &p)
{
    if(p->right == nullptr)
        return p;
    getMax(p->right);
}


template <class T>
node<T>* binary_search_tree<T>::getSuccessor(node<T>* &p)
{
    if(p->right != nullptr)
    {
        return getMin(p->right);
    }
    else
    {
        node<T> *parent = p->parent;
        node<T> *current = p;

        while(parent != nullptr && current == parent->right)
        {
            current = parent;
            parent = current->parent;
        }

        return parent;
    }
}

template <class T>
node<T>* binary_search_tree<T>::searchFromTree(node<T>* &p, const T &searchItem)
{
    if(p->key == searchItem)
        return p;
    else if(p == nullptr)
        return nullptr;
    else if(searchItem > p->key)
        searchFromTree(p->right, searchItem);
    else
        searchFromTree(p->left, searchItem);
}


template <class T>
node<T>* binary_search_tree<T>::insertToTree(node<T>* &p, const T &insertItem)
{
    if(p == NULL)
    {
        p = new node<T>(insertItem);
        return p;        
    }
    else if(p->key == insertItem)
    {
        cerr << "\nCant insert an existed item!!";
        return nullptr;
    }
    else if(insertItem > p->key)
    {
        insertToTree(p->right, insertItem);
        p->right->parent = p;
    }
    else
    {
        insertToTree(p->left, insertItem);
        p->left->parent = p;
    }
}


template <class T>
void binary_search_tree<T>::deleteFromTree(node<T>* &p, const T &deleteItem)
{
    node<T> *temp, deletedNode = searchFromTree(p, deleteItem);
    if(deletedNode == nullptr)
    {
        cerr << "\nThe item to be deleted is not in the tree!";
    }
    else
    {
        if(!deletedNode->left && !deletedNode->right)
        {
            temp = deletedNode;
            deletedNode = nullptr;
            delete temp;
        }
        else if(deletedNode->left && !deletedNode->right)
        {
            temp = deletedNode;
            deletedNode->left->parent = deletedNode->parent;
            deletedNode = deletedNode->left;
            delete temp;
        }
        else if(!deletedNode->left && deletedNode->right)
        {
            temp = deletedNode;
            deletedNode->right->parent = deletedNode->parent;
            deletedNode = deletedNode->right;
            delete temp;
        }
        else
        {
            T successorKey = getSuccessor(deletedNode)->key;
            deletedNode->key = successorKey;
            deleteFromTree(deletedNode->right, successorKey);
        }
    }
}


template <class T>
node<T>* binary_search_tree<T>::search(const T &searchItem)
{
    return searchFromTree(this->root, searchItem);
}

template <class T>
node<T>* binary_search_tree<T>::insert(const T &insertItem)
{
    return insertToTree(this->root, insertItem);
}

template <class T>
void binary_search_tree<T>::delete_node(const T &deleteItem)
{
    deleteFromTree(this->root, deleteItem);
}



#endif