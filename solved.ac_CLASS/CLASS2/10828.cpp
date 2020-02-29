// 스택
#include <iostream>
using namespace std;

template<typename T>
struct Node 
{
    T val; Node* next;
    Node() { next = nullptr; }
 };

template<typename T>
class Stack
{
public:
    Stack()
    {
        _size = 0;
        _top = new Node<T>;
    }
    ~Stack()
    {
        Node<T>* tmp;
        while(_top->next != nullptr)
        {
            tmp = _top->next;
            _top->next = tmp->next;
            delete tmp;
        }
        delete _top;
    }

    void push(T val)
    {
        Node<T>* newNode = new Node<T>;
        if (newNode)
        {
            newNode->val = val;
            newNode->next = _top->next;
            _top->next = newNode;
            ++_size;
        }
    }

    T pop()
    {
        if (empty()) return -1;
        Node<T>* tmp = _top->next;
        T ret_val = tmp->val;
        _top->next = tmp->next;
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
    T top()
    {
        if (empty()) return -1;
        return _top->next->val;
    }
private:
    Node<T>* _top;
    int _size;
};

int n, num;
string s;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    Stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> num;
            st.push(num);
        }
        else if (s == "pop")
        {
            cout << st.pop() << '\n';
        }
        else if (s == "size")
        {
            cout << st.size() << '\n';
        }
        else if (s == "empty")
        {
            cout << st.empty() << '\n';
        }
        else if (s == "top")
        {
            cout << st.top() << '\n';
        }
    }
}