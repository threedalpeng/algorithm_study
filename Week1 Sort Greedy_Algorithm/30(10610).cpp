#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string N;
	cin >> N;
	int sum = 0;
	bool zero_exists = false;
	for (int i = 0; i < N.length(); i++)
	{
		if (N[i] == '0')
		{
			zero_exists = true;
		}
		sum += (N[i] - '0');
	}
	if (zero_exists && sum % 3 == 0)
	{
		sort(N.rbegin(), N.rend());
		cout << N;
	}
	else
	{
		cout << -1;
	}
}