// ㄷㄷㄷㅈ / 19535
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll N, a, b;
vector<ll> graph[300'001];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll count_g = 0;
    ll count_d = 0;
    for (int i = 1; i <= N; i++) {
        ll size = graph[i].size();
        count_g += ((size * (size - 1) * (size - 2)) / 6);
        ll count_d_sub = 0;
        for (auto j : graph[i]) {
            count_d_sub += (size - 1) * (graph[j].size() - 1);
        }
        count_d += count_d_sub;
    }
    count_d /= 2;
    // cout << count_d << ' ' << count_g << '\n';
    if (count_d == count_g * 3) {
        cout << "DUDUDUNGA\n";
    }
    else if (count_d > count_g * 3) {
        cout << "D\n";
    }
    else {
        cout << "G\n";
    }
}