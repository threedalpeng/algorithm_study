// 기타 레슨
#include <iostream>
using namespace std;
typedef long long ll;
ll N, M, L[100002];

bool pos(int length)
{
    int sum = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + L[i] > length)
        {
            sum = 0;
            ++count;
        }
        sum += L[i];
    }

    if (sum != 0) ++count;

    return count <= M;
}

int main()
{
    cin >> N >> M;
    ll max = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> L[i];
        if (max < L[i]) max = L[i];
    }
    ll first = max, last = 1e9 / M, mid;
    while(first <= last)
    {
        mid = (first + last) >> 1;
        if (pos(mid)) last = mid - 1;
        else first = mid + 1;
    }
    cout << first;
}