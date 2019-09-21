#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int result, sum;
	if (arr[0] != 1)
	{
		result = 1;
	}
	else {
		for (int i = 0; i < N; i++)
		{
			sum = 0;
			for (int j = 0; j < i; j++)
			{
				sum += arr[j];
			}
			if (sum + 1 < arr[i])
			{
				result = sum + 1;
				break;
			}
			if (i == N - 1)
			{
				result = sum + 1 + arr[i];
			}
		}
	}
	cout << result << '\n';
    return 0;
}