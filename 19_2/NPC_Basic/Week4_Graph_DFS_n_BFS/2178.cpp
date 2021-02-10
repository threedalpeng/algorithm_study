#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, M, c, min, cnt;
vector<string> maze;
struct point {
    int x, y;
    int level = 1;
    bool operator==(const point& p) const {
        return (x == p.x && y == p.y);
    }
    bool operator!=(const point& p) const {
        return !(*this == p);
    }
    const point operator+(const point& p) const {
        return { x + p.x, y + p.y };
    }
    bool inside(const point& end) const {
        return (0 < x && x <= end.x && 0 < y && y <= end.y);
    }
    bool valid(const vector<string>& maze) const {
        return maze[x][y] - '0';
    }
};
queue<point> q;
point drt[4] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    const point end_point = { N, M };
    string input;
    maze.resize(N + 1, " ");
    for (int i = 1; i <= N; i++) {
        cin >> input;
        maze[i] += input;
    }

    point cur, next;
    q.push({ 1, 1 });
    while (((cur = q.front()) != end_point) && !q.empty()) {
        q.pop();
        for (int i = 0; i < 4; i++) {
            next = cur + drt[i];
            next.level = cur.level + 1;
            if (next.inside(end_point) && next.valid(maze)) {
                maze[next.x][next.y] = '0';
                q.push(next);
            }
        }
    }
    cout << cur.level;
}