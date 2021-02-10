// 최소 힙
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class PriorityQueue {
public:
    PriorityQueue(bool (*_comp)(T t1, T t2), int _size = 0) {
        comp = _comp;
        heap.resize(_size + 1);
    }

    T top() {
        if (empty()) return 0;
        return heap[1];
    }

    void push(T _data) {
        heap.push_back(_data);
        int idx = _size + 1;
        while (idx != 1) {
            int par = idx / 2;
            if (comp(heap[par], _data)) {
                heap[idx] = heap[par];
                idx = par;
            }
            else
                break;
        }
        heap[idx] = _data;
        ++_size;
    }
    void pop() {
        if (empty()) return;
        T last = heap[_size];
        int par_idx = 1;
        while (int chd_idx = next_child_idx(par_idx)) {
            if (comp(last, heap[chd_idx])) {
                heap[par_idx] = heap[chd_idx];
                par_idx = chd_idx;
            }
            else
                break;
        }
        heap[par_idx] = last;
        --_size;
    }

    int size() { return _size; }
    bool empty() { return size() == 0; }

private:
    vector<T> heap;
    bool (*comp)(T t1, T t2);
    int _size = 0;
    int next_child_idx(int par) {
        int left = par * 2, right = left + 1;
        if (left > size()) return 0;
        else if (left == size())
            return 2 * par;
        else {
            if (comp(heap[left], heap[right])) return right;
            else
                return left;
        }
    }
};

/* custom comparison function */
template <typename T>
bool descending(T t1, T t2) { return t1 > t2; };

int N, x;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    PriorityQueue<int> MinHeap(descending);
    while (N--) {
        cin >> x;
        if (x == 0) {
            cout << MinHeap.top() << '\n';
            MinHeap.pop();
        }
        else {
            MinHeap.push(x);
        }
    }
}