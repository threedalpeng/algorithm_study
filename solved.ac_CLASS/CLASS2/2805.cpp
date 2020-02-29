// 나무 자르기
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;
ll T[1000002], sum[1000002];

bool pos(ll limit)
{
    ll st = 1, fn = N, mid, idx = 0;
    while(st <= fn)
    {
        mid = (st + fn) >> 1;
        if (T[mid]>=limit) idx = mid, fn = mid-1;
        else st = mid + 1;
    }
    return (sum[N]-(sum[idx - 1] + (N - idx + 1) * limit)) >= M;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) cin >> T[i];
    sort(T + 1, T + 1 + N);
    ll st = 0, fn = T[N], mid, res = -1;
    for (ll i = 1; i <= N; i++) sum[i] = sum[i - 1] + T[i];
    while(st <= fn)
    {
        mid = (st + fn) >> 1;
        if (pos(mid)) res = mid, st = mid + 1;
        else fn = mid - 1;
    }
    cout << res;
    return 0;
}