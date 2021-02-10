// K번째 수
#include <iostream>
using namespace std;

long N, k;

bool pos(long num) {
    long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (num > N * i ? N : (num - 1) / i);
    }
    if (k >= sum + 1) return true;
    else
        return false;
}

int main() {
    cin >> N >> k;
    long first = 1, last = N * N, res = -1;
    while (first <= last) {
        long mid = (first + last) >> 1;
        if (pos(mid)) first = mid + 1, res = mid;
        else
            last = mid - 1;
    }
    cout << res;
}