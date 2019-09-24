#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    ll sum = 0, M;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    sort(A, A+N);

    cin >> M;
    if (M >= sum)
    {
        cout << A[N-1];
        return 0;
    }

    ll first = 0, last = sum, mid, result = -1;
    while(first <= last)
    {
        mid = (first + last) >> 1;
        int idx = 0;
        ll exp = 0;
        while(idx < N)
        {
            if (A[idx] > mid)
            {
                exp += (mid * (N-idx));
                break;
            }
            exp += A[idx++];
        }
        cout << "mid : " << mid << "\texp : " << exp << '\n';
        if (exp <= M) first = mid + 1, result = mid;
        else last = mid - 1;
    }
    cout << result;
}