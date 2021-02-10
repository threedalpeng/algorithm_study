template <typename T>
struct Node {
    T val;
    Node* next;
    Node() { next = nullptr; }
};

template <typename T>
class Stack {
public:
    Stack() {
        _size = 0;
        _top = new Node<T>;
    }
    ~Stack() {
        Node<T>* tmp;
        while (_top->next != nullptr) {
            tmp = _top->next;
            _top->next = tmp->next;
            delete tmp;
        }
        delete _top;
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>;
        if (newNode) {
            newNode->val = val;
            newNode->next = _top->next;
            _top->next = newNode;
            ++_size;
        }
    }

    T pop() {
        if (empty())
            return -1;
        Node<T>* tmp = _top->next;
        T ret_val = tmp->val;
        _top->next = tmp->next;
        delete tmp;
        --_size;
        return ret_val;
    }

    int size() {
        return _size;
    }
    int empty() {
        return _size == 0;
    }
    T top() {
        if (empty())
            exit(-1);
        return _top->next->val;
    }

private:
    Node<T>* _top;
    int _size;
};