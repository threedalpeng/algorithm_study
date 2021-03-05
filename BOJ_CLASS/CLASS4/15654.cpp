// N과 M (5)
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
vector<int> v, p;
vector<bool> check;

void printVec(int depth = 0) {
    if (depth == M) {
        for (auto i : p) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            check[i] = true;
            p.push_back(v[i]);
            printVec(depth + 1);
            p.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    v.resize(N);
    check.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    printVec();
}