// 마인크래프트
#include <iostream>
#include <fstream>
using namespace std;

int N, M, B, land[501][501];

int time(int floor)
{
    int fill = 0, remove = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (land[i][j] > floor) remove += (land[i][j] - floor);
            else if (land[i][j] < floor) fill += (floor - land[i][j]);
        }
    }
    if (fill > B + remove) return 1e9;
    return remove * 2 + fill;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M >> B;
    int mn = 256, mx = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> land[i][j];
            if (land[i][j] < mn) mn = land[i][j];
            if (mx < land[i][j]) mx = land[i][j];
        }
    }
    int res, rt = 1e9 - 1;
    for (int i = mn; i <= mx; i++)
    {
        int t = time(i);
        if (t <= rt) res = i, rt = t;
    }
    cout << (rt == 1e9 - 1 ? 0 : rt) << ' ' << res;
}