// 덩치
#include <iostream>
using namespace std;

struct P {
    int x, y;
};
int n;
P p[51];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        for (int j = 1; j <= n; j++) {
            if (p[i].x < p[j].x && p[i].y < p[j].y) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}