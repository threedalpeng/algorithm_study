#include <bits/stdc++.h>
using namespace std;

int h[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++) {
        cin >> h[i];
    }

    if (h[0] < h[1] && h[1] < h[2] && h[2] < h[3]) {
        cout << "Uphill\n";
    }
    else if (h[0] > h[1] && h[1] > h[2] && h[2] > h[3]) {
        cout << "Downhill\n";
    }
    else if (h[0] == h[1] && h[1] == h[2] && h[2] == h[3]) {
        cout << "Flat Land\n";
    }
    else {
        cout << "Unknown\n";
    }
}