// 공유기 설치
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, C, X[200002];

bool pos(ll dist)
{
    int idx = 0, count = 0;
    for (ll i = 0; i < N; i++)
    {
        if(X[i] - X[idx] >= dist)
        {
            idx = i;
            ++count;
        }
    }
    ++count;
    return count >= C;
}

int main()
{
    cin >> N >> C;
    for (ll i = 0; i < N; i++) cin >> X[i];
    sort(X, X + N);
    int first = 1, last = X[N-1] - X[0], mid, result = -1;
    while(first <= last)
    {
        mid = (first + last) >> 1;
        if (pos(mid)) first = mid + 1, result = mid;
        else last = mid - 1;
    }
    cout << result;
    return 0;
}