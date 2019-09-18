#include <iostream>
using namespace std;

int partition(int* arr, int first, int last);
void quicksort(int* arr, int first, int last);

int main()
{
    int N;
    cin >> N;
    
    int* arr = new int[N];
    for (int i{0}; i < N; i++)
    {
        cin >> arr[i];
    }
    

}

int partition(int* arr, int first, int last)
{
    int pivot = arr[first];
    int left = first + 1;
    int right = last;
    while(left < right)
    {
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right++;
        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    
}