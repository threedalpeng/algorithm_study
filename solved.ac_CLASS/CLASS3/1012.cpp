// 유기농 배추
#include <iostream>
#include <algorithm>
using namespace std;

int T, M, N, K, X, Y, a[50][50];

void dfs(int x, int y)
{
    if ((x < 0 || M <= x) || (y < 0 || N <= y)) return;
    if (a[x][y] == 1) a[x][y] = 2;
    else return;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> M >> N >> K;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = 0;
        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            a[X][Y] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[i][j] == 1)
                {
                    ++cnt;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
}