// 에디터
#include <deque>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    char command, abc;
    cin >> s >> n;
    deque<char> dq = { '\0' };
    for (int i = 0; i < s.length(); i++) {
        dq.push_back(s[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == 'P') {
            cin >> abc;
            dq.push_back(abc);
        }
        else if (command == 'L') {
            if (dq.back() != '\0') {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if (command == 'D') {
            if (dq.front() != '\0') {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else if (command == 'B') {
            if (dq.back() != '\0') {
                dq.pop_back();
            }
        }
    }
    while (dq.back() != '\0') {
        dq.push_back(dq.front());
        dq.pop_front();
    }
    for (auto it = dq.begin(); it < (--dq.end()); it++) {
        cout << (*it);
    }
    cout << '\n';
}