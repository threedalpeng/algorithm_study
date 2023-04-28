// 단어 정렬
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;
string s[20001];

template <typename T>
bool order(T t1, T t2) {
    if (t1.size() == t2.size())
        return t1 < t2;
    else
        return t1.size() < t2.size();
}

/*
 Quicksort in ascending order.
 */
template <typename T>
void quicksort(T* arr, int first, int last, bool (*cmp)(T, T)) {
    int left, right;
    T pivot, tmp;
    if (first < last) {
        left = first - 1;
        right = last + 1;
        pivot = arr[(first + last) / 2];
        while (true) {
            while (cmp(arr[++left], pivot))
                ;
            while (cmp(pivot, arr[--right]))
                ;
            if (left >= right) break;
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
        quicksort(arr, first, left - 1, cmp);
        quicksort(arr, right + 1, last, cmp);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    quicksort(s, 0, n - 1, order);
    string prv = "";
    for (int i = 0; i < n; i++) {
        if (prv != s[i]) {
            cout << s[i] << '\n';
            prv = s[i];
        }
    }
}