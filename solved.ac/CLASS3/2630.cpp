// 색종이 만들기
#include <iostream>
using namespace std;

struct P {
    int blue, white;
    bool operator==(P p) { return (blue == p.blue) && (white == p.white); }
    P operator+(P p) { return { blue + p.blue, white + p.white }; }
};
int n;
bool color[129][129];
P blue{ 1, 0 }, white{ 0, 1 };

P divide(int n, int x, int y) {
    if (n == 1) {
        if (color[x][y]) return { 1, 0 };
        else
            return { 0, 1 };
    }
    P n1 = divide(n / 2, x, y);
    P n2 = divide(n / 2, x + n / 2, y);
    P n3 = divide(n / 2, x, y + n / 2);
    P n4 = divide(n / 2, x + n / 2, y + n / 2);
    if ((n1 == blue) && (n2 == blue) && (n3 == blue) && (n4 == blue))
        return blue;
    else if ((n1 == white) && (n2 == white) && (n3 == white) && (n4 == white))
        return white;
    else
        return n1 + n2 + n3 + n4;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> color[i][j];
    P res = divide(n, 1, 1);
    cout << res.white << '\n'
         << res.blue;
}