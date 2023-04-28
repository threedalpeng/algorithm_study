// 뱀과 사다리 게임
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N, M;
int ls[101];
int f, s;
bool check[101] = {
    false,
};
int level = 0;

vector<int> cur, tmp;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= 100; i++) {
        ls[i] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> f >> s;
        ls[f] = s;
    }
    for (int i = 0; i < M; i++) {
        cin >> f >> s;
        ls[f] = s;
    }

    cur.push_back(1);
    while (!check[100]) {
        level++;
        for (auto i : cur) {
            for (int j = i + 1; j <= i + 6; j++) {
                if (j > 100) break;
                int r = ls[j];
                if (!check[r]) {
                    check[r] = true;
                    tmp.push_back(r);
                }
            }
            //cout << i << ' ';
        }
        cur = tmp;
        tmp.clear();
        //cout << '\n';
    }

    cout << level << '\n';
}