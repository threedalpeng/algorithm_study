// 나는야 포켓몬 마스터 이다솜
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    string name;
    vector<string> pv(1);
    map<string, int> pm;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> name;
        pv.push_back(name);
        pm[name] = i;
    }
    for (int i = 1; i <= M; i++) {
        cin >> name;
        if ('0' <= name[0] && name[0] <= '9') {
            cout << pv[atoi(name.c_str())] << '\n';
        }
        else {
            cout << pm[name] << '\n';
        }
    }
}