#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<pii> VM;
multiset<int> C;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    VM.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> VM[i].second >> VM[i].first;
    }

    int a;
    for (int i = 0; i < K; i++) {
        cin >> a;
        C.insert(a);
    }

    sort(VM.rbegin(), VM.rend());

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (C.empty())
            break;
        int v = VM[i].second;
        auto gte_it = C.lower_bound(v);
        if (gte_it != C.end()) {
            sum += VM[i].first;
            C.erase(gte_it);
        }
    }
    cout << sum << '\n';
}