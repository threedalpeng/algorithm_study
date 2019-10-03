#include <iostream>
using namespace std;
long A[301][301];
int main()
{
    int N, M, K, i, j, x, y;
    cin >> N >> M;
    for(int c = 1; c <= N; c++)
        for (int r = 1; r <= M; r ++) cin >> A[c][r];
    cin >> K;
    long sum = 0;
    for (int t = 0; t < K; t++)
    {
        cin >> i >> j >> x >> y;
        for(int c = i; c <= x; c++)
            for(int r = j; r <= y; r++) sum += A[c][r];
        cout << sum << '\n';
        sum = 0;
    }
    return 0;
}