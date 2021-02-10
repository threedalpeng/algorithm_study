#include <iostream>
using namespace std;

template <typename T>
void swap_element(T& t1, T& t2);

template <typename T>
void print_arr(T* arr, int first, int last);

template <typename T>
bool ascending(T t1, T t2);

template <typename T>
void insertionSort(T* arr, int first, int last, bool (*cmp)(T, T) = ascending);

// main function to check sort
int main() {
    int arr[12] = { 3, 7, 2, 9, 5, 2, 6, 4, 1, 8, 10, 5 };
    // string arr[12] = {"asn", "dkf", "xfn", "dks", "wfe", "fwe", "aos", "dqw","zdp", "cvj", "zdp", "kxj"};
    cout << "before sorting:\n\t";
    print_arr(arr, 0, 12 - 1);
    insertionSort(arr, 0, 12 - 1, ascending);
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
Insertion sort in ascending order.
*/
template <typename T>
void insertionSort(T* arr, int first, int last, bool (*cmp)(T, T)) {
    T key;
    for (int i = first + 1; i <= last; ++i) {
        key = arr[i];
        for (int j = i - 1; j >= first; --j) {
            if (cmp(arr[j], key))
                break;
            arr[j + 1] = arr[j];
            arr[j] = key;
        }
    }
}