// 폴리오미노
#include <iostream>
using namespace std;

string s, ans;

int main() {
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'X') {
            ++cnt;
            if (cnt == 4) {
                ans += "AAAA";
                cnt = 0;
            }
        }
        else {
            if (cnt % 2) {
                ans = "-1";
                break;
            }
            else if (cnt == 2)
                ans += "BB";
            cnt = 0;
            ans += ".";
        }
    }
    if (cnt % 2)
        ans = "-1";
    else if (cnt == 2)
        ans += "BB";
    cout << ans;
}