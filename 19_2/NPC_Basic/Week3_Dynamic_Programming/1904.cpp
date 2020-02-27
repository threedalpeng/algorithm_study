// 01타일
#include <iostream>
using namespace std;

const int limit = 15746;
int N, DP[1'000'001];

int main()
{
    cin >> N;
    DP[1] = 1, DP[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        DP[i] = (DP[i-1] + DP[i-2]) % limit;
    }
    cout << DP[N];
}