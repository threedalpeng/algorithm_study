// 로프
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, w[100'001];
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> w[i];
    sort(w + 1, w + N + 1, greater<int>());
    int mx = 0;
    for (int i = 1; i <= N; i++)
    {
        mx = max(w[i] * i, mx);
    }
    cout << mx << '\n';
}