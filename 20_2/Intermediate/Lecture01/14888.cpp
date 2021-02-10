// 연산자 끼워넣기
#include <iostream>
using namespace std;

int N, numbers[12];
struct Result {
    int max = -1e9;
    int min = 1e9;
};

Result backtrack(int plus, int minus, int mul, int div, int depth) {
    Result ret;
    if (depth == 1) {
        ret.max = numbers[depth];
        ret.min = numbers[depth];
        return ret;
    }
    Result res;
    if (plus) // plus
    {
        res = backtrack(plus - 1, minus, mul, div, depth - 1);
        ret.max = max(ret.max, res.max + numbers[depth]);
        ret.min = min(ret.min, res.min + numbers[depth]);
    }
    if (minus) {
        res = backtrack(plus, minus - 1, mul, div, depth - 1);
        ret.max = max(ret.max, res.max - numbers[depth]);
        ret.min = min(ret.min, res.min - numbers[depth]);
    }
    if (mul) {
        res = backtrack(plus, minus, mul - 1, div, depth - 1);
        ret.max = max(ret.max, res.max * numbers[depth]);
        ret.min = min(ret.min, res.min * numbers[depth]);
    }
    if (div) {
        res = backtrack(plus, minus, mul, div - 1, depth - 1);
        ret.max = max(ret.max, res.max / numbers[depth]);
        ret.min = min(ret.min, res.min / numbers[depth]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    int pl, mi, mu, di;
    cin >> pl >> mi >> mu >> di;
    Result res = backtrack(pl, mi, mu, di, N);
    cout << res.max << '\n'
         << res.min << '\n';
}