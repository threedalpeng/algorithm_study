#include <functional>
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T val;
    Node<T>*left = nullptr, *right = nullptr;

    Node() {}
    Node(T _val) : val(_val) {}
};

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        _size = 0;
        _root = nullptr;
    }

    void insert(T _val)
    {
        Node<T>** walk = &_root;
        while (*walk)
        {
            T curVal = (*walk)->val;
            if (curVal == _val)
                return;
            else if (curVal > _val)
                walk = &((*walk)->left);
            else
                walk = &((*walk)->right);
        }
        *walk = new Node<T>(_val);
        ++_size;
    }
    void remove(T _val)
    {
        Node<T>** walk = &_root;
        if (_size == 0)
            return;

        while (*walk)
        {
            T curVal = (*walk)->val;
            if (curVal == _val)
                break;
            else if (curVal > _val)
                walk = &((*walk)->left);
            else
                walk = &((*walk)->right);
        }
        if (!(*walk))
            return;

        Node<T>* cur = (*walk);
        (*walk) = nullptr;
        Node<T>* left = cur->left;
        if (cur->right)
        {
            (*walk) = cur->right;
            if (cur->left)
            {
                Node<T>* rep = (*walk);
                while (rep->left)
                {
                    rep = rep->left;
                }
                rep->left = left;
            }
        }
        else if (cur->left)
        {
            (*walk) = left;
        }
        delete cur;
        --_size;
    }

    bool find(T _val)
    {
        Node<T>** walk = &_root;
        while (*walk)
        {
            T curVal = (*walk)->val;
            if (curVal == _val)
                return true;
            else if (curVal > _val)
                walk = &((*walk)->left);
            else
                walk = &((*walk)->right);
        }
        return false;
    }

    void print()
    {
        cout << "size: " << size() << '\n';
        traverse([](Node<T>* root) { cout << root->val << ' '; }, _root);
        cout << '\n';
    }

    int size()
    {
        return _size;
    }

private:
    Node<T>* _root;
    int _size;

    void traverse(function<void(Node<T>*)> func, Node<T>* root)
    {
        if (!root)
            return;
        traverse(func, root->left);
        func(root);
        traverse(func, root->right);
    }
};

int main()
{
    BinarySearchTree<int> BST;
    BST.insert(4);
    BST.insert(9);
    BST.insert(7);
    BST.print();
    BST.remove(9);
    BST.print();
    BST.remove(4);
    BST.print();
    BST.insert(5);
    BST.insert(2);
    BST.print();
    BST.remove(2);
    BST.remove(5);
    BST.remove(7);
    BST.print();
}