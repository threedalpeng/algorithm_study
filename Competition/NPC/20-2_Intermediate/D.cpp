#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, C;
int w[5001];

int find_upper(int n, int last)
{
    int f = 0, l = last, mid, res = - 1;
    while (f <= l)
    {
        mid = (f + l) >> 1;
        if (w[mid] <= n) f = mid + 1, res = mid;
        else l = mid - 1;
    }
    return res;
}

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }
    sort(w, w + N);
    
    ll sum = 0, f, last;
    for (int i = N-1; i >= 0; i--)
    {
        sum = w[i];
        last = i - 1;
        for (int j = 0; j < 2 && sum < C; j++)
        {
            f = find_upper(C-sum, last);
            if (f == -1) 
                break;
            sum += w[f];
            last = f - 1;
        }
        if (sum == C)
            break;
    }
    cout << (sum == C ? 1 : 0) << '\n';
}