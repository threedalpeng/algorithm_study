// 수 정렬하기
#include <iostream>
using namespace std;

int n, arr[1001];

void quicksort(int* a, int first, int last) {
    int left, right, pivot, tmp;
    if (first < last) {
        left = first;
        right = last;
        pivot = a[(first + last) >> 1];
        while (true) {
            while (a[left] < pivot)
                ++left;
            while (pivot < a[right])
                --right;
            if (left >= right) break;
            tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
        quicksort(a, first, left - 1);
        quicksort(a, right + 1, last);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}