// 숫자 정사각형
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
string s[50];

int size(int x, int y, int l = 1)
{
    int match = s[y][x];
    if (s[y + l - 1][x] == match && s[y][x + l - 1] == match && s[y + l - 1][x + l - 1] == match)
    {
        return l * l;
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
    int mx = 1, area;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            for (int l = 2; l <= min(N - y, M - x); l++)
            {
                if (mx < (area = size(x, y, l)))
                    mx = area;
            }
        }
    }
    cout << mx;
}