#ifndef __TREE_NODE__
#define __TREE_NODE__

#include "binary_tree_node.h"

template <class T>
class binary_tree
{
    protected:
        node<T> *root;

    private:
        void copyTree(node<T>* &copiedTreeRoot, node<T>* &otherTreeRoot);

        void destroyTree(node<T>* &p);

        void inorderTraversal(node<T> *p, void (*visit) (T&));

        void preorderTraversal(node<T> *p, void (*visit) (T&));

        void postorderTraversal(node<T> *p, void (*visit) (T&));

        int treeHeight(node<T> *p) const;

        int max(int x, int y) const;

        int treeNodesCount(node<T> *p) const;

        int treeLeavesCount(node<T> *p) const;

    public:
        const binary_tree<T>& operator = (const binary_tree<T>&);

        bool empty() const;

        void inorder(void (*visit) (T&) = [] (T& x) {cout << x << "";});
        void preorder(void (*visit) (T&) = [] (T& x) {cout << x << "";});
        void postorder(void (*visit) (T&) = [] (T& x) {cout << x << "";});

        int height() const;

        int nodesCount() const;

        int leavesCount() const;

        void destroy();

        binary_tree();

        binary_tree(const binary_tree& otherTree);

        ~binary_tree();
};

/*--------------private function------------------*/

//copy func
template <class T>
void binary_tree<T>::copyTree(node<T>* &copiedTreeRoot, node<T>* &otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        //copy node data
        copiedTreeRoot = new node<T>;
        copiedTreeRoot->key = otherTreeRoot->key;


        //copy left node
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        if(copiedTreeRoot->left)
            copiedTreeRoot->left->parent = copiedTreeRoot;  //set parent

        //copy right node
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
        if(copiedTreeRoot->right)
            copiedTreeRoot->right->parent = copiedTreeRoot;
    }
}
//end copy


template <class T>
void binary_tree<T>::destroyTree(node<T>* &p)
{
    if(p != nullptr)
    {
        destroyTree(p->left);
        destroyTree(p->right);
        delete p;
        p = nullptr;
    }
}


template <class T>
void binary_tree<T>::inorderTraversal(node<T> *p, void (*visit) (T&))
{
    if(p != nullptr)
    {
        inorderTraversal(p->left, *visit);
        (*visit)(p->key);
        inorderTraversal(p->right, *visit);
    }
}



template <class T>
void binary_tree<T>::preorderTraversal(node<T> *p, void (*visit) (T&))
{
    if(p != nullptr)
    {
        (*visit)(p->key);
        inorderTraversal(p->left, *visit);
        inorderTraversal(p->right, *visit);
    }
}

template <class T>
void binary_tree<T>::postorderTraversal(node<T> *p, void (*visit) (T&))
{
    if(p != nullptr)
    {
        inorderTraversal(p->left, *visit);
        inorderTraversal(p->right, *visit);
        (*visit)(p->key);
    }
}

template<class T>
int binary_tree<T>::max(int x, int y) const
{
    return x > y ? x : y;
}

template<class T>
int binary_tree<T>::treeHeight(node<T> *p) const
{
    if(p == nullptr) 
        return 0;
    else
        return 1 + max(treeHeight(p->left), treeHeight(p->right));
}


template<class T>
int binary_tree<T>::treeNodesCount(node<T> *p) const
{
    if(p == nullptr)
        return 0;
    else
        return 1 + treeNodesCount(p->left) + treeNodesCount(p->right);
}


template<class T>
int binary_tree<T>::treeLeavesCount(node<T> *p) const
{
    if(p->left == nullptr && p->right == nullptr)
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}


/*-------public function ---------------*/
template<class T>
const binary_tree<T>& binary_tree<T>::operator = (const binary_tree<T>& other)
{
    if(this != &other)
    {
        if(this->root != nullptr)
        {
            destroy(root);
        }

        copyTree(this->root, other.root);
    }

    return *this;
}


template<class T>
bool binary_tree<T>::empty() const
{
    return this->root != nullptr;
}


template<class T>
void binary_tree<T>::inorder(void (*visit) (T&))
{
    inorderTraversal(this->root, visit);
}



template<class T>
void binary_tree<T>::preorder(void (*visit) (T&))
{
    preorderTraversal(this->root, visit);
}


template<class T>
void binary_tree<T>::postorder(void (*visit) (T&))
{
    postorderTraversal(this->root, visit);
}


template<class T>
int binary_tree<T>::height() const
{
    return treeHeight(this->root);
}


template<class T>
int binary_tree<T>::nodesCount() const
{
    return treeNodesCount(this->root);
}

template<class T>
int binary_tree<T>::leavesCount() const
{
    return treeLeavesCount(this->root);
}


template<class T>
void binary_tree<T>::destroy()
{
    destroyTree(this->root);
}


template<class T>
binary_tree<T>::binary_tree()
{
    root = nullptr;
}


template<class T>
binary_tree<T>::binary_tree(const binary_tree& otherTree)
{
    copyTree(this->root, otherTree.root);
}


template<class T>
binary_tree<T>::~binary_tree()
{
    destroyTree(this->root);
}


#endif


