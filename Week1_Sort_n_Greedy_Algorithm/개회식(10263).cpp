#include <iostream>
using namespace std;

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
			while (arr[++left] > pivot);
			while (arr[--right] < pivot);
			if (left >= right) break;
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
		quicksort(arr, first, left - 1);
		quicksort(arr, right + 1, last);
	}
}

int main()
{
    int N;
    cin >> N;
    int* h = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
    quicksort(h, 0, N-1);
    int min = h[0] + 0;
    for (int i = 1; i < N; i++) 
    {
        if (min > h[i] + i) min = h[i] + i;
    }
    cout << min;
}