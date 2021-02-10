// 그룹 단어 체커
#include <iostream>
#include <string>
using namespace std;

int main() {
    bool alpha[26];
    int N;
    string s;
    char prev;
    int count = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++)
            alpha[j] = false;
        cin >> s;
        prev = s[0];
        for (int j = 1; j < s.length(); j++) {
            if (s[j] != prev) {
                if (alpha[s[j] - 'a'] == true) {
                    ++count;
                    break;
                }
                alpha[prev - 'a'] = true;
            }
            prev = s[j];
        }
    }
    cout << N - count;
}