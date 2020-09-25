#include <iostream>
using namespace std;

template <typename T>
void print_arr(T* arr, int first, int last)
{
    for (int i = first; i <= last; i++)
        cout << arr[i] << ' ';
}

template <typename T>
bool ascending(T t1, T t2)
{
    return t1 < t2;
}

/*
 Quicksort in ascending order.
 */
template <typename T>
void quicksort(T* arr, int first, int last, bool (*cmp)(T, T) = ascending)
{
    int left, right;
    T pivot, tmp;
    if (first < last)
    {
        left = first;
        right = last;
        pivot = arr[(first + last) / 2];
        while (true)
        {
            while (cmp(arr[left], pivot))
                ++left;
            while (cmp(pivot, arr[right]))
                --right;
            if (left >= right)
                break;
            tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            ++left, --right;
        }
        quicksort(arr, first, left - 1, cmp);
        quicksort(arr, right + 1, last, cmp);
    }
}

// main function to check quicksort
int main()
{
    // int arr[12] = {3, 7, 2, 9, 5, 2, 6, 4, 1, 8, 10, 5};
    string arr[12] = {"asn", "dkf", "xfn", "dks", "wfe", "fwe", "aos", "dqw", "zdp", "cvj", "zdp", "kxj"};
    cout << "before sorting:\n\t";
    print_arr(arr, 0, 12 - 1);
    quicksort(arr, 0, 12 - 1, ascending);
    cout << "\nafter sorting:\n\t";
    print_arr(arr, 0, 12 - 1);
    return 0;
}