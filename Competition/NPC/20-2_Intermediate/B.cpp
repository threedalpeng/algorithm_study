#include <iostream>
using namespace std;

int next_milk(int m) { return (m < 2 ? m + 1 : 0); }

int main() {
    int n, milk, next, cnt = 0;
    cin >> n;
    next = 0;
    for (int i = 0; i < n; i++) {
        cin >> milk;
        if (next == milk) {
            cnt++;
            next = next_milk(milk);
        }
    }
    cout << cnt << '\n';
}