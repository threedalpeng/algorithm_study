// OX퀴즈
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    vector<int> num_o;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++) {
        num_o.clear();
        num_o.push_back(-1);
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'X') {
                num_o.push_back(j);
            }
        }
        num_o.push_back(s.size());
        int rst = 0;
        for (int j = 0; j < num_o.size() - 1; j++) {
            int num = num_o[j + 1] - num_o[j];
            for (int i = 1; i < num; i++) {
                rst += i;
            }
        }
        cout << rst << '\n';
    }
}