#include <bits/stdc++.h>
using namespace std;

int N, T;
set<int> primes;

int main() {
    vector<int> primes_under_31 = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (int i = 2; i < 1000; i++) {
        primes.insert(i);
    }
    for (auto i : primes_under_31) {
        for (int j = 2; j <= 1000 / i; j++) {
            primes.erase(i * j);
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;
        int a, b, c = 0;
        for (auto _a : primes) {
            for (auto _b : primes) {
                if (_a + _b >= N)
                    break;
                if (primes.find(N - _a - _b) != primes.end()) {
                    c = N - _a - _b;
                    a = _a;
                    b = _b;
                    break;
                }
            }
            if (c)
                break;
        }
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}