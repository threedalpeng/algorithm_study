// 숫자 카드 2
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, num, cards[20'000'001];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        ++cards[num + 10'000'000];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << cards[num + 10'000'000] << ' ';
    }
}