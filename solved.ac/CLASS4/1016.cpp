// 제곱 ㄴㄴ 수
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

ll X, mn, mx;
bool check[1'000'001];

int main() {
    cin >> mn >> mx;
    ll mx_div = ceil(sqrt(mx));
    for (ll i = 2; i <= mx_div; i++) {
        ll div = i * i;
        ll st = (mn % div ? ((mn / div) + 1) * div : mn);
        for (ll j = st - mn; j <= mx - mn; j += div) {
            check[j] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= mx - mn; i++) {
        if (!check[i])
            cnt++;
    }
    cout << cnt;
}