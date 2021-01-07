#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
    int N, t, m, a, b;
    char c;
    cin >> a >> b >> N;
    priority_queue<pii> blue, red;
    int n_present = 0;
    for (int i = 0; i < N; i++) {
        cin >> t >> c >> m;
        if (c == 'B')
            blue.push(make_pair(t, m));
        else
            red.push(make_pair(t, m));
        n_present += m;
    }

    for (int i = 0; i < n_present; i++) {
        if (blue.top().first < red.top().first) {
            blue.top().second;
            blue.top().
        }
    }
}