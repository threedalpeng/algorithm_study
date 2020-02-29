// 랜선 자르기
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int K, N;
ll lan[10001];

bool check(ll l)
{
    int n = 0;
    for (int i = 0; i < K; i++)
    {
        n += lan[i] / l;
        if (n >= N) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    ll max = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> lan[i];
        max = (max > lan[i] ? max : lan[i]);
    }
    ll first = 1, last = max, result = -1; 
    while(first <= last)
    {
        ll mid = (first + last) >> 1;
        if (check(mid)) first = mid + 1, result = mid;
        else last = mid - 1;
    }
    cout << result;
}