// 이친수
#include <iostream>
using namespace std;
using ll = long long;

int N;
ll DP[91];

int main()
{
    cin >> N;
    DP[1] = 1, DP[2] = 1;
    for (int i = 3; i <= N; i++)
        DP[i] = DP[i - 1] + DP[i - 2];
    cout << DP[N];
}