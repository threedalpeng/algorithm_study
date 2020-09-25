#include <bits/stdc++.h>
using namespace std;

int M, N, L, n_count = 0;
vector<int> sh;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> L;
    int a, b;
    sh.push_back(0);
    for (int i = 0; i < M; i++)
    {
        cin >> a;
        sh.push_back(a);
    }
    sh.push_back(1'000'000'000);
    sort(sh.begin(), sh.end());
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        int first = 0, last = sh.size() - 1, mid, res = -1;
        while (first <= last)
        {
            mid = (first + last >> 1);
            if (a >= sh[mid])
                first = mid + 1, res = mid;
            else
                last = mid - 1;
        }
        // cout << sh[res] << ' ' << a << ' ' << sh[res + 1] << '\n';
        if (res == 0)
        {
            if (sh[1] - a + b <= L)
                ++n_count;
            continue;
        }
        if (res == sh.size() - 2)
        {
            if (a - sh[res] + b <= L)
                ++n_count;
            continue;
        }

        if (a - sh[res] < sh[res + 1] - a)
        {
            if ((a - sh[res]) + b <= L)
                ++n_count;
        }
        else
        {
            if (sh[res + 1] - a + b <= L)
                ++n_count;
        }
    }
    cout << n_count << '\n';
}