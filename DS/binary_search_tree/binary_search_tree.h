#ifndef _M_BINARY_SEARCH_TREE_
#define _M_BINARY_SEARCH_TREE_


template <class T>
struct node
{
    T key;
    node *parent, *left, *right;

    node(){}

    node(T k, node *p = nullptr, node *l = nullptr, node *r = nullptr)
    {
        key = k;
        parent = p;
        left = l;
        right = r;
    }

};


template<class T>
class binary_search_tree
{
    private:
        node<T> *root;

        node<T>* maxTreeNode(node<T> *&p)
        {
            if(p->right == nullptr)
                return p;
            maxTreeNode(p->right);
        }

        node<T>* minTreeNode(node<T> *&p)
        {
            if(p->left == nullptr)
                return p;
            minTreeNode(p->left);
        }

        node<T>* getSuccessor(node<T> *&p)
        {
            if(p->right != nullptr)
                return minTreeNode(p->right);
            else
            {
                node<T> *parent = p->parent;
                node<T> *current = p;

                while((parent != nullptr) && (current == parent->right))
                {
                    current = parent;
                    parent = current->parent;
                }

                return parent;
            }
        }

        int max(int a, int b) const
        {
            return a > b ? a : b;
        }

        int treeHeight( node<T> *&p)
        {
            if(p == nullptr) 
                return 0;
            else
                return 1 + max(treeHeight(p->left), treeHeight(p->right));
        }

        int treeLeaves( node<T> *&p)
        {
            if(p == nullptr)
                return 0;
            if(p->left == nullptr && p->right == nullptr)
                return 1;
            else
                return treeLeaves(p->left) + treeLeaves(p->right);
        }

        int treeNodes(node<T> *&p)
        {
            if(p == nullptr)
                return 0;
            else
                return 1 + treeNodes(p->left) + treeNodes(p->right);
        }

        void copyTree(node<T> *&copiedTreeRoot, node<T> *&otherTreeRoot)
        {
            if(otherTreeRoot == nullptr)
                copiedTreeRoot = nullptr;
            else
            {
                copiedTreeRoot = new node<T>(otherTreeRoot->key);
                copyTree(copiedTreeRoot->left, otherTreeRoot->left);
                if(copiedTreeRoot->left != nullptr)
                    copiedTreeRoot->left->parent = copiedTreeRoot;

                copyTree(copiedTreeRoot->right, otherTreeRoot->right);
                if(copiedTreeRoot->right != nullptr)
                    copiedTreeRoot->right->parent = copiedTreeRoot;
            }
        }

        void destroyTree(node<T> *&p)
        {
            if(p != nullptr)
            {
                destroyTree(p->left);
                destroyTree(p->right);
                delete p;
                p = nullptr;
            }
        }

        node<T>* searchFromTree(node<T> * p, T value)
        {
            
            if(p == nullptr)
                return nullptr;
            else if(p->key == value)
                return p;
            else if(value > p->key)
                return searchFromTree(p->right, value);
            else
                return searchFromTree(p->left, value);
        }

        void insertToTree(node<T>* &p, T value)
        {
            
            if(p == nullptr)
            {
                p = new node<T>(value);
                return;
            }
            else if(p->key == value)
            {
                cerr << "\nThe item to be inserted is already in the tree!!";
                return;
            }
            else if(value > p->key)
            {
                insertToTree(p->right, value);
                p->right->parent = p;
            }
            else
            {
                insertToTree(p->left, value);
                p->left->parent = p;
            }
        }

        void removeFromTree(node<T>* &p, T value)
        {
            if(p->key == value)
            {
                node<T>* temp;
                if(p->left == nullptr && p->right == nullptr)
                {
                    temp = p;
                    p = nullptr;
                    delete temp;
                }
                else if(p->right != nullptr && p->left == nullptr)
                {
                    temp = p;
                    p->right->parent = p->parent;
                    p = p->right;
                    delete temp;
                }
                else if(p->right == nullptr && p->left != nullptr)
                {
                    temp = p;
                    p->left->parent = p->parent;
                    p = p->left;
                    delete temp;
                }
                else
                {
                    int successorKey = getSuccessor(p)->key;
                    p->key = successorKey;
                    removeFromTree(p->right, successorKey);
                }
            }
            else if(value > p->key)
                removeFromTree(p->right, value);
            else
                removeFromTree(p->left, value);
        }

        void inorderTraversal(node<T> *&p)
        {
            if(p != nullptr)
            {
                inorderTraversal(p->left);
                cout << p->key << " ";
                inorderTraversal(p->right);
            }
        }

        void preorderTraversal(node<T> *&p)
        {
            if(p != nullptr)
            {
                cout << p->key << " ";
                preorderTraversal(p->left);
                preorderTraversal(p->right);
            }
        }

        void postorderTraversal(node<T> *&p)
        {
            if(p != nullptr)
            {
                postorderTraversal(p->left);
                postorderTraversal(p->right);
                cout << p->key << " ";
            }
        }

        int sumNode(node<T> *&p)
        {
            if(p == nullptr)
                return 0;
            else
                return p->key + sumNode(p->left) + sumNode(p->right);
        }

    public:
        binary_search_tree()
        {
            root = nullptr;
        }

        binary_search_tree(binary_search_tree &other)
        {
            copyTree(this->root, other.root);
        }

        binary_search_tree& operator=(binary_search_tree&other)
        {
            copyTree(this->root, other.root);
            return *this;
        }

        ~binary_search_tree()
        {
            destroyTree(root);
        }

        T& successor()
        {
            return getSuccessor(this->root);
        }

        void inorder()
        {
            inorderTraversal(this->root);
        }
        void preorder()
        {
            preorderTraversal(this->root);
        }
        void postorder()
        {
            postorderTraversal(this->root);
        }

        int height()
        {
            return treeHeight(this->root);
        }
        int leaves()
        {
            return treeLeaves(this->root);
        }
        int nodes()
        {
            return treeNodes(this->root);
        }
        int sum()
        {
            return sumNode(this->root);
        }


        void insert(T value)
        {
            insertToTree(this->root, value);
        }
        void remove(T value)
        {
            if(searchFromTree(this->root, value) == nullptr)
            {
                cerr << "\nThe item to be deleted is not in the tree!";
                return;
            }
            removeFromTree(this->root, value);
        }
        node<T>* search(T value)
        {
            return searchFromTree(this->root, value);
        }
};






#endif