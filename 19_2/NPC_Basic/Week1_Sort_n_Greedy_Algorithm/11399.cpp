// ATM
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int time;
	priority_queue<int, vector<int>, greater<int>> P;
	for (int i = 0; i < N; i++)
	{
		cin >> time;
		P.push(time);
	}

	int result = 0;
	for (int i = N; i > 0; i--)
	{
		result += (P.top() * i);
		P.pop();
	}

	cout << result;
}
