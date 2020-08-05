// 큐
#include <iostream>
using namespace std;

template<typename T>
struct Node 
{
    T val; Node<T>* next, * prev;
    Node() { next = nullptr; prev = nullptr; }
 };

template<typename T>
class Queue
{
public:
    Queue()
    {
        _size = 0;
        _front = new Node<T>;
        _back = new Node<T>;
        _front->next = _back;
        _back->prev = _front;
    }
    ~Queue()
    {
        Node<T>* tmp;
        while(_front->next != nullptr)
        {
            tmp = _front->next;
            _front->next = tmp->next;
            delete tmp;
        }
        delete _front;
    }

    void push(T val)
    {
        Node<T>* newNode = new Node<T>;
        if (newNode)
        {
            newNode->val = val;
            newNode->next = _back;
            newNode->prev = _back->prev;
            _back->prev->next = newNode;
            _back->prev = newNode;
            ++_size;
        }
    }

    T pop()
    {
        if (empty()) return -1;
        Node<T>* tmp = _front->next;
        T ret_val = tmp->val;
        _front->next = tmp->next;
        _front->next->prev = _front;
        delete tmp;
        --_size;
        return ret_val;
    }

    int size()
    {
        return _size;
    }
    int empty()
    {
        return _size == 0;
    }
    T front()
    {
        if (empty()) return -1;
        return _front->next->val;
    }
    T back()
    {
        if (empty()) return -1;
        return _back->prev->val;
    }
private:
    Node<T>* _front;
    Node<T>* _back;
    int _size;
};

int n, num;
string s;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    Queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            cout << q.pop() << '\n';
        }
        else if (s == "size")
        {
            cout << q.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (s == "front")
        {
            cout << q.front() << '\n';
        }
        else if (s == "back")
        {
            cout << q.back() << '\n';
        }
    }
}