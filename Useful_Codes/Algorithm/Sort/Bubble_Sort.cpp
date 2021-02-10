#include <iostream>
using namespace std;

template <typename T>
void swap_element(T& t1, T& t2);

template <typename T>
void print_arr(T* arr, int first, int last);

template <typename T>
bool ascending(T t1, T t2);

template <typename T>
void bubbleSort(T* arr, int first, int last, bool (*cmp)(T, T));

// main function to check sort
int main() {
    int arr[12] = { 3, 7, 2, 9, 5, 2, 6, 4, 1, 8, 10, 5 };
    // string arr[12] = {"asn", "dkf", "xfn", "dks", "wfe", "fwe", "aos", "dqw","zdp", "cvj", "zdp", "kxj"};
    cout << "before sorting:\n\t";
    print_arr(arr, 0, 12 - 1);
    bubbleSort(arr, 0, 12 - 1, ascending);
    cout << "\nafter sorting:\n\t";
    print_arr(arr, 0, 12 - 1);
    return 0;
}

template <typename T>
void swap_element(T& t1, T& t2) {
    T tmp = t1;
    t1 = t2;
    t2 = tmp;
}

template <typename T>
void print_arr(T* arr, int first, int last) {
    for (int i = first; i <= last; i++)
        cout << arr[i] << ' ';
}

template <typename T>
bool ascending(T t1, T t2) {
    return t1 < t2;
}

/*
 Bubble sort in ascending order.
 */
template <typename T>
void bubbleSort(T* arr, int first, int last, bool (*cmp)(T, T) = ascending) {
    for (int i = last; i > first; --i)
        for (int j = first; j < i; ++j)
            if (cmp(arr[j + 1], arr[j]))
                swap_element(arr[j], arr[j + 1]);
}