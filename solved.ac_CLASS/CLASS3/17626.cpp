// Four Squares
#include <iostream>
#include <algorithm>
using namespace std;

int N, DP[50'001], sqr[250];

int main()
{
    cin >> N;
    for (int w = 1; (sqr[w] = w * w) <= N; w++);
    for (int i = 2; i <= N; i++) DP[i] = 1e9;
    DP[1] = 1; 
    for (int i = 2; i <= N; i++)
    {
        for (int w = 1; sqr[w] <= i; w++)
        {
            DP[i] = min(DP[i - sqr[w]] + 1, DP[i]);
        }
        // cout << i << ": " << DP[i] << '\n';
    }
    cout << DP[N];
}