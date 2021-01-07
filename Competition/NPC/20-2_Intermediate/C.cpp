#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pplll = pair<pll, ll>;

ll N;
vector<pplll> meets;
vector<ll> DP;

int main()
{
    cin >> N;
    ll st, ed, p;
    meets.push_back({{0, 0}, 0});
    for (int i = 0; i < N; i++)
    {
        cin >> st >> ed >> p;
        meets.push_back({{st, ed}, p});
    }
    sort(meets.begin(), meets.end());

    DP.resize(N + 1);
    DP[0] = 0;
    DP[1] = meets[1].second;
    if (N >= 2)
        DP[2] = max(meets[1].second, meets[2].second);
    for (int i = 3; i <= N; i++)
    {
        DP[i] = max(meets[i].second + DP[i-2], max(meets[i].second + DP[i-3], DP[i-1]));
    }
    cout << DP[N] << '\n';
}