// 파도반 수열
#include <iostream>
using namespace std;

int T, N;
long long DP[101] = {0, 1, 1, 1, 2, 2, };

int main()
{
    cin >> T;
    for (int i = 6; i <= 100; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 5];
    }
    while(T--)
    {
        cin >> N;
        cout << DP[N] << '\n';
    }
}