// 개회식
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int* h = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }
	sort(h, h + N, greater<int>());
    int min = N;
    for (int i = 0; i < N; i++) 
    {
        if (min > h[i] + i) min = h[i] + i;
    }
    cout << min;
}