// 듣보잡
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    string name;
    vector<string> nl, nh, nlh;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> name;
        nl.push_back(name);
    }
    for (int i = 0; i < M; i++) {
        cin >> name;
        nh.push_back(name);
    }
    sort(nl.begin(), nl.end());
    sort(nh.begin(), nh.end());
    for (int i = 0, j = 0; i < N && j < M;) {
        if (nl[i] == nh[j]) {
            nlh.push_back(nl[i]);
            i++, j++;
        }
        else if (nl[i] > nh[j])
            j++;
        else
            i++;
    }
    cout << nlh.size() << '\n';
    for (auto p : nlh)
        cout << p << '\n';
}