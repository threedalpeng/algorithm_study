#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
int N, M;
vector<p> G[100001];
bool visited[100001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A >> B >> C;
        G[A].push_back(p(B, C));
        G[B].push_back(p(A, C));
    }
    int from, to;
    cin >> from >> to;
    p cur;
    queue<p> q;
    vector<int> weight;
    q.push(p(from, 2e9));
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.first == to) {
            weight.push_back(cur.second);
        }
        else {
            visited[cur.first] = true;
            for (auto x : G[cur.first]) {
                if (!visited[x.first]) {
                    q.push(p(x.first, min(x.second, cur.second)));
                }
            }
        }
    }
    sort(weight.begin(), weight.end(), greater<int>());
    cout << weight.front();
}