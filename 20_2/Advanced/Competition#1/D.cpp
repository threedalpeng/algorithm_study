#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int t, n, k;
vector<pii> p;

bool avail(int r2, int n_elev)
{
    int mx = -1e9, mn = 1e9, cnt = 0;
    for (int i = 0; i < p.size(); i++)
    {
        mx = max(mx, p[i].second);
        mn = min(mn, p[i].second);
        if (mx - mn > r2)
        {
            ++cnt;
            if (cnt > n_elev)
            {
                return false;
            }
            mx = p[i].second;
            mn = p[i].second;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a, b;
        p.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            p.push_back(make_pair(a, b));
        }
        sort(p.begin(), p.end());

        int first = 0, last = 2e8, res = -1, mid;
        while (first <= last)
        {
            mid = (first + last) >> 1;
            if (avail(mid, k - 1))
                last = mid - 1, res = mid;
            else
                first = mid + 1;
        }
        cout << fixed << setprecision(1) << static_cast<double>(res) / 2 << endl;
    }
}