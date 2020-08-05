// 1, 2, 3 더하기
#include <iostream>
using namespace std;

int t, n, DP[11];

int main()
{
    cin >> t;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i <= 10; i++)
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3]; 
    while(t--)
    {
        cin >> n;
        cout << DP[n] << '\n';
    }
}