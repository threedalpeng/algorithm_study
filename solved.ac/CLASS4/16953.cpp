// A -> B
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

const int CANNOT_REACH = 2e9;

int invOp(int target, int src) {
    if (target == src) {
        return 0;
    }
    if (target < src) {
        return CANNOT_REACH;
    }

    int depth = CANNOT_REACH;
    if (target % 2 == 0) {
        depth = min(depth, 1 + invOp(target / 2, src));
    }
    else if (target % 10 == 1) {
        depth = min(depth, 1 + invOp((target - 1) / 10, src));
    }

    return depth;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    int result = invOp(B, A);
    if (result == CANNOT_REACH) {
        cout << -1 << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}
