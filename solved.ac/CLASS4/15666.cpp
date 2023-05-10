// N과 M (12)
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int N, M;
set<int> s;
vector<int> v;
vector<int> stack;

void seq(int cur, int depth) {
    stack.push_back(v[cur]);
    if (depth == 1) {
        for (int i = 0; i < stack.size(); i++) {
            cout << stack[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i = cur; i < v.size(); i++) {
            seq(i, depth - 1);
        }
    }
    stack.pop_back();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        s.insert(a);
    }
    v.assign(s.begin(), s.end());

    for (int i = 0; i < v.size(); i++) {
        seq(i, M);
    }
}