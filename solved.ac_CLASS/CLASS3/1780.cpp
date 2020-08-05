// 종이의 개수
#include <iostream>
using namespace std;

int N, paper[2187][2187], num[3];

void divide(int n, int x, int y)
{
    if (n == 1)
    {
        ++num[paper[x][y] + 1];
        return;
    }
    else
    {
        int stnd = paper[x][y];
        bool match = true;
        for (int i = x; i < x + n; i++)
        {
            for (int j = y; j < y + n; j++)
                if (stnd != paper[i][j])
                {
                    match = false;
                    break;
                }
            if (!match) break;
        }
        if (match)
        {
            ++num[stnd+1];
        }
        else
        {
            n /= 3;
            divide(n, x+0*n, y+0*n);
            divide(n, x+1*n, y+0*n);
            divide(n, x+2*n, y+0*n);
            divide(n, x+0*n, y+1*n);
            divide(n, x+1*n, y+1*n);
            divide(n, x+2*n, y+1*n);
            divide(n, x+0*n, y+2*n);
            divide(n, x+1*n, y+2*n);
            divide(n, x+2*n, y+2*n);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    divide(N, 0, 0);
    for (int i = 0; i <= 2; i++)
        cout << num[i] << '\n';
}