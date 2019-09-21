#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int num;
	priority_queue<int, vector<int>, less<int>> pos; // positive
	priority_queue<int, vector<int>, greater<int>> neg; // negative & 0
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num > 0) 
		{
			pos.push(num);
		}
		else 
		{
			neg.push(num);
		}
	}

	int result = 0;
	while (pos.size() > 1)
	{
		int num1 = pos.top();
		pos.pop();
		int num2 = pos.top();
		pos.pop();
		result += (num1 * num2 > num1 + num2 ? num1*num2 : num1+num2);
	}
	if (!pos.empty())
	{
		result += pos.top();
		pos.pop();
	}

	while (neg.size() > 1)
	{
		int group = neg.top();
		neg.pop();
		group *= neg.top();
		neg.pop();
		result += group;
	}
	if (!neg.empty())
	{
		result += neg.top();
		neg.pop();
	}

	cout << result;
}