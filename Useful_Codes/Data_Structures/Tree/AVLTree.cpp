#include <functional>
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct Node {
    T val;
    Node<T>*left = nullptr, *right = nullptr;
    int height = 1, balanceFactor = 0;

    Node() {}
    Node(T _val) : val(_val) {}

    void update() {
        int leftHeight = (left ? left->height : 0);
        int rightHeight = (right ? right->height : 0);
        height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
        balanceFactor = rightHeight - leftHeight;
    }
};

template <typename T>
class AVLTree {
public:
    AVLTree() {
        _size = 0;
        _root = nullptr;
    }

    void insert(T _val) {
        Node<T>** walk = &_root;
        stack<Node<T>**> updateList;
        while (*walk) {
            updateList.push(walk);
            T curVal = (*walk)->val;
            if (curVal == _val)
                return;
            else if (curVal > _val)
                walk = &((*walk)->left);
            else
                walk = &((*walk)->right);
        }

        *walk = new Node<T>(_val);
        while (!updateList.empty()) {
            rebalance(updateList.top());
            updateList.pop();
        }

        ++_size;
    }
    void remove(T _val) {
        Node<T>** walk = &_root;
        if (_size == 0)
            return;

        stack<Node<T>**> updateList;
        while (*walk) {
            updateList.push(walk);
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
        if (cur->right) {
            (*walk) = cur->right;
            if (cur->left) {
                Node<T>* rep = (*walk);
                while (rep->left) {
                    rep = rep->left;
                }
                rep->left = left;
            }
        }
        else if (cur->left) {
            (*walk) = left;
        }
        delete cur;

        postorder_traverse(
            function<void(Node<T>**)>([this](Node<T>** node) {
                this->rebalance(node);
            }),
            updateList.top());
        updateList.pop();
        while (!updateList.empty()) {
            rebalance(updateList.top());
            updateList.pop();
        }

        --_size;
    }

    bool find(T _val) {
        Node<T>** walk = &_root;
        while (*walk) {
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

    void print() {
        cout << "size: " << size() << '\n';
        inorder_traverse(
            [](Node<T>** root) {
                cout << (*root)->val << '(' << (*root)->height << ')' << ' ';
            },
            &_root);
        cout << '\n';
    }

    int size() {
        return _size;
    }

private:
    Node<T>* _root;
    int _size;

    void inorder_traverse(function<void(Node<T>**)> func, Node<T>** root) {
        if (!(*root))
            return;
        inorder_traverse(func, &((*root)->left));
        func(root);
        inorder_traverse(func, &((*root)->right));
    }
    void postorder_traverse(function<void(Node<T>**)> func, Node<T>** root) {
        if (!(*root))
            return;
        postorder_traverse(func, &((*root)->left));
        postorder_traverse(func, &((*root)->right));
        func(root);
    }

    void rebalance(Node<T>** node) {
        if (!(*node))
            return;

        (*node)->update();

        if ((*node)->balanceFactor < -1) {
            if ((*node)->left && (*node)->left->balanceFactor == 1) // LR-rotate
            {
                lrotate(&((*node)->left));
            }
            rrotate(node);
        }
        else if ((*node)->balanceFactor > 1) {
            if ((*node)->right && (*node)->right->balanceFactor == -1) // RL-rotate
            {
                rrotate(&((*node)->right));
            }
            lrotate(node);
        }
    }

    void lrotate(Node<T>** node) {
        Node<T>* cur = (*node);
        Node<T>* right = cur->right;
        Node<T>* right_child = right->left;

        (*node) = right;
        right->left = cur;
        cur->right = right_child;

        (*node)->left->update();
        (*node)->update();
    }

    void rrotate(Node<T>** node) {
        Node<T>* cur = (*node);
        Node<T>* left = cur->left;
        Node<T>* left_child = left->right;

        (*node) = left;
        left->right = cur;
        cur->left = left_child;

        (*node)->right->update();
        (*node)->update();
    }
};

int main() {
    AVLTree<int> tree;
    tree.insert(5);
    tree.print();
    tree.insert(6);
    tree.print();
    tree.insert(7);
    tree.print();
    tree.insert(4);
    tree.print();
    tree.insert(3);
    tree.print();
    tree.insert(9);
    tree.print();
    tree.insert(8);
    tree.print();
    tree.insert(1);
    tree.print();
    tree.insert(2);
    tree.print();
    tree.insert(0);
    tree.print();
    tree.remove(4);
    tree.print();
    tree.remove(2);
    tree.print();
    tree.remove(1);
    tree.print();
    tree.remove(6);
    tree.print();
    tree.remove(0);
    tree.print();
    tree.remove(3);
    tree.print();
    tree.remove(5);
    tree.print();
}