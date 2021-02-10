#include <bits/stdc++.h>
using namespace std;

int N;
int a[1'000];
set<int> checkNumber;
bool numExists(int n) {
    return (checkNumber.find(n) != checkNumber.cend());
}
vector<int> np;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (!numExists(a[i])) {
            checkNumber.insert(a[i]);
            np.push_back(a[i]);
        }
    }

    int res = 0;
    for (auto ban : np) {
        int llen = 0, cnum = a[0], clen = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] != ban) {
                if (a[i] == cnum) {
                    clen++;
                    if (clen > llen) {
                        llen = clen;
                    }
                }
                else {
                    cnum = a[i];
                    clen = 1;
                }
            }
        }
        if (res < llen) {
            res = llen;
        }
    }
    cout << res << '\n';
}