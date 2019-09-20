#include <iostream>
using namespace std;

/*
 Quicksort in ascending order.
 TODO: modify this so that we can select an order-defining function.
 */
template<typename T>
void quicksort(T* arr, int first, int last)
{
	int left, right, pivot;
	T tmp;
	if (first < last)
	{
		left = first - 1;
		right = last + 1;
		pivot = arr[(first + last) / 2];
		while (true) {
			while (arr[++left] < pivot);
			while (arr[--right] > pivot);
			if (left >= right) break;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		quicksort(arr, first, left - 1);
		quicksort(arr, right + 1, last);
	}
}

// main function to check quicksort
int main()
{
    int arr[10] = {3, 7, 2, 9, 6, 4, 1, 8, 10, 5};
    cout << "before sorting:\n\t";
    for (int i : arr) cout << i << " ";
    quicksort(arr, 0, 10 - 1);
    cout << "\nafter sorting:\n\t";
    for (int i : arr) cout << i << " ";
    return 0;
}