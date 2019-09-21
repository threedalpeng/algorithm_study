#include <cstdio>
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
    scanf("%lld %lld", &N, &M);
    for (ll i = 1; i <= N; i++) scanf("%lld", &T[i]);
    sort(T + 1, T + 1 + N); // sort an array
    ll st = 0, fn = T[N], mid, res;
    // initialize an array cummulatively 
    for (ll i = 1; i <= N; i++) sum[i] = sum[i - 1] + T[i];
    // binary search
    while(st <= fn)
    {
        mid = (st + fn) >> 1;
        if (pos(mid)) res = mid, st = mid + 1;
        else fn = mid - 1;
    }
    printf("%lld", res);
    return 0;
}