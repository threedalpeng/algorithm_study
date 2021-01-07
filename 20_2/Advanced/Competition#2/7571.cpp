// 점 모으기
#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<int> x(M);
    vector<int> y(M);
    for (int i = 0; i < M; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    int xm = x[M / 2], ym = y[M / 2];
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        sum += abs(x[i] - xm);
        sum += abs(y[i] - ym);
    }
    cout << sum << '\n';
}