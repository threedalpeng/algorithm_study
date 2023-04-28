// N과 M (2)
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void printCombination(int start = 0, int depth = N) {
    if (depth == 0) {
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= N - depth; i++) {
        v.push_back(i + 1);
        printCombination(i + 1, depth - 1);
        v.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    printCombination(0, M);
}