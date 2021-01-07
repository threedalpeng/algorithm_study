#include <bits/stdc++.h>
using namespace std;

int score[6][3];

bool bt(int f, int s) {
    if (f == 5) return true;

    int nf = (s == 5 ? f + 1 : f);
    int ns = (s == 5 ? f + 2 : s + 1);

    bool rslt = false;
    for (int i = 0; i < 3; i++) {
        --score[f][i];
        --score[s][2 - i];
        if (score[f][i] >= 0 && score[s][2 - i] >= 0)
            rslt |= bt(nf, ns);
        ++score[f][i];
        ++score[s][2 - i];
    }
    return rslt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 0; t < 4; t++) {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++) {
                cin >> score[i][j];
                sum += score[i][j];
            }
        if (sum == 30)
            cout << bt(0, 1) << ' ';
        else
            cout << "0 ";
    }
}