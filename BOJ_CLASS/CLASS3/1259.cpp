// 팰린드롬수
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool palindrome(string s) {
    for (auto i = s.begin(), j = s.end() - 1; i <= j; i++, j--)
        if (*i != *j) return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    while (s != "0") {
        if (palindrome(s)) cout << "yes\n";
        else
            cout << "no\n";
        cin >> s;
    }
}