// 소수 찾기
#include <cmath>
#include <iostream>
using namespace std;

int n, num;

bool isPrime(int p) {
    if (p <= 1) return false;
    if (p % 2 == 0) return (p == 2 ? true : false);
    for (int i = 3; i <= sqrt(p); i += 2) {
        if (p % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (isPrime(num)) ++cnt;
    }
    cout << cnt;
}