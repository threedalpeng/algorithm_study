// 나무 탈출
#include <iostream>
#include <vector>
using namespace std;

int n, a, b;
int v[500002];
bool check[500002];
vector<int> leaf;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // for (int i = 0; i < 500002; i++) { check[i] = false;}
    v[1] = -1;

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        if (v[a] != 0) {
            v[b] = a;
            check[a] = true;
        }
        else if (v[b] != 0) {
            v[a] = b;
            check[b] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!check[i]) leaf.push_back(i);
    }

    long long int res = 0;
    for (int i = 0; i < leaf.size(); i++) {
        int p = leaf[i], len = 0;
        while (p != 1) {
            p = v[p];
            ++len;
        }
        res += len;
    }
    cout << (res % 2 ? "Yes" : "No");
}