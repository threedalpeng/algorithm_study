// 집합
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned set = 0;
    int M, x;
    string command;
    cin >> M;
    while (M--) {
        cin >> command;
        if (command == "add") {
            cin >> x;
            unsigned mask = 0x1 << (x - 1);
            set |= mask;
        }
        else if (command == "remove") {
            cin >> x;
            unsigned mask = 0x1 << (x - 1);
            set = ~((~set) | mask);
        }
        else if (command == "check") {
            cin >> x;
            cout << ((set >> (x - 1)) & 0x1) << '\n';
        }
        else if (command == "toggle") {
            cin >> x;
            unsigned mask = 0x1 << (x - 1);
            set ^= mask;
        }
        else if (command == "all") {
            set = 0xFFFFF;
        }
        else if (command == "empty") {
            set = 0x0;
        }
    }
}