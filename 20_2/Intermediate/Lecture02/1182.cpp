#include <bits/stdc++.h>
using namespace std;

int N, S, cnt = 0;
int num[20];

void bf(int sum, int idx)
{
    if (idx == N)
    {
        if (sum == S)
            ++cnt;
        return;
    }
    bf(sum, idx+1);
    bf(sum + num[idx], idx+1);
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    bf(0, 0);
    if (S == 0)
        cnt--;
    cout << cnt << '\n';
}