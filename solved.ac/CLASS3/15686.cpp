// 치킨 배달
#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int N, M, num;
vector<pii> home, chicken;
vector<int> combination;

inline int dist(pii x, pii y) { return abs(x.first - y.first) + abs(x.second - y.second); }

int getChickenDist(int cntChicken, int start = 0, int depth = M) {
    if (depth == 0) {
        int sum = 0, mn;
        for (auto h : home) {
            mn = 1000;
            for (auto c : combination) {
                mn = min(dist(chicken[c], h), mn);
            }
            sum += mn;
        }
        /*
        cout << "[ ";
        for (auto c : combination) {
            cout << c << ' ';
        }
        cout << "] => ";
        cout << sum << "\n";
        */
        return sum;
    }

    int mn = 100000;
    for (int i = start; i <= cntChicken - depth; i++) {
        combination.push_back(i);
        mn = min(getChickenDist(cntChicken, i + 1, depth - 1), mn);
        combination.pop_back();
    }
    return mn;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            switch (num) {
            case 1:
                home.push_back({ i, j });
                break;
            case 2:
                chicken.push_back({ i, j });
                break;
            }
        }
    }

    cout << getChickenDist(chicken.size()) << '\n';
}