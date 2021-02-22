// 아기 상어
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, graph[20][20], sharkSize, cntFishEaten;
bool check[20][20];
pii sharkPos;

pii drt[4] = {
    { -1, 0 },
    { 0, -1 },
    { 0, 1 },
    { 1, 0 },
};

inline void toggleCheck(pii p) {}

int find_available_fish() {
    int mv_dist = 0;
    vector<pii> v, nv;
    v.push_back(sharkPos);
    check[sharkPos.first][sharkPos.second] = true;
    while (!v.empty()) {
        mv_dist++;
        pii nextPos;
        for (auto pt : v) {
            for (int i = 0; i < 4; i++) {
                nextPos = { pt.first + drt[i].first, pt.second + drt[i].second };
                if (0 <= nextPos.first && nextPos.first < N && 0 <= nextPos.second && nextPos.second < N && !check[nextPos.first][nextPos.second]) {
                    int fish = graph[nextPos.first][nextPos.second];
                    if (fish <= sharkSize) {
                        nv.push_back(nextPos);
                        check[nextPos.first][nextPos.second] = true;
                    }
                }
            }
        }
        sort(nv.begin(), nv.end());
        for (auto pt : nv) {
            int fish = graph[pt.first][pt.second];
            if (0 < fish && fish < sharkSize) {
                graph[pt.first][pt.second] = 0;
                sharkPos = pt;
                if (++cntFishEaten == sharkSize) {
                    ++sharkSize;
                    cntFishEaten = 0;
                }
                return mv_dist;
            }
        }
        v = nv;
        nv.clear();
    }
    return -1;
}

int main() {
    //cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                sharkPos = { i, j };
                graph[i][j] = 0;
            }
        }

    sharkSize = 2;
    int dist = 0, fish_dist = 0;
    while ((fish_dist = find_available_fish()) > 0) {
        dist += fish_dist;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                check[i][j] = false;
    }

    cout << dist;
}