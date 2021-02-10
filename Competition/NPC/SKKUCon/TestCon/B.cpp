#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    bool isPossible = true;
    for (auto c : str) {
        switch (c) {
        case 'H':
        case 'I':
        case 'N':
        case 'O':
        case 'S':
        case 'X':
        case 'Z':
            break;
        default:
            isPossible = false;
            break;
        }
        if (!isPossible) break;
    }

    if (isPossible) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}