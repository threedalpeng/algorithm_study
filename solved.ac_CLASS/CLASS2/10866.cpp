// 덱
#include <iostream>
using namespace std;

template<typename T>
struct Node 
{
    T val; Node<T>* next, * prev;
    Node() { next = nullptr; prev = nullptr; }
 };

template<typename T>
class Deque
{
public:
    Deque()
    {
        _size = 0;
        _front = new Node<T>;
        _back = new Node<T>;
        _front->next = _back;
        _back->prev = _front;
    }
    ~Deque()
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
    
    void push_front(T val)
    {
        Node<T>* newNode = new Node<T>;
        if (newNode)
        {
            newNode->val = val;
            newNode->next = _front->next;
            newNode->prev = _front;
            _front->next->prev = newNode;
            _front->next = newNode;
            ++_size;
        }
    }

    void push_back(T val)
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

    T pop_front()
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

    T pop_back()
    {
        if (empty()) return -1;
        Node<T>* tmp = _back->prev;
        T ret_val = tmp->val;
        _back->prev = tmp->prev;
        _back->prev->next = _back;
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
    Deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push_front")
        {
            cin >> num;
            dq.push_front(num);
        }
        else if (s == "push_back")
        {
            cin >> num;
            dq.push_back(num);
        }
        else if (s == "pop_front")
        {
            cout << dq.pop_front() << '\n';
        }
        else if (s == "pop_back")
        {
            cout << dq.pop_back() << '\n';
        }
        else if (s == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (s == "front")
        {
            cout << dq.front() << '\n';
        }
        else if (s == "back")
        {
            cout << dq.back() << '\n';
        }
    }
}