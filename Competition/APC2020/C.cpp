/**
* 개인적으로 작성한 코드 참조. 동일 코드가
* https://github.com/threedalpeng/algorithm_study 
* 에 있을 수 있음 
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int ttoi(string tm) {
    return stoi(tm.substr(0, 2)) * 60 + stoi(tm.substr(3, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    string tm;
    vector<pii> fscore, lscore;
    fscore.resize(N + 1);
    lscore.resize(N + 1);
    int ctm = 180, tmi, id, p, s;
    for (int i = 0; i < M; i++) {
        cin >> tm >> id >> p >> s;
        tmi = ttoi(tm);
        if (tmi < 180) {
            fscore[p].first++;
            fscore[p].second += (tmi + (s - 1) * 20);
        }
        lscore[p].first++;
        lscore[p].second += (tmi + (s - 1) * 20);
    }
}