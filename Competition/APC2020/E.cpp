/**
* 개인적으로 작성한 코드 참조. 동일 코드가
* https://github.com/threedalpeng/algorithm_study 
* 에 있을 수 있음 
*/
#include <bits/stdc++.h>
using namespace std;

char swap_map[128] = {0}, mirr_map[128] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    swap_map['a'] = 'A';
    swap_map['B'] = 'b';
    swap_map['D'] = 'd';
    swap_map['e'] = 'E';
    swap_map['h'] = 'H';
    swap_map['i'] = 'I';
    swap_map['L'] = 'l';
    swap_map['N'] = 'n';
    swap_map['m'] = 'M';
    swap_map['o'] = 'O';
    swap_map['P'] = 'p';
    swap_map['Q'] = 'q';
    swap_map['R'] = 'r';
    swap_map['s'] = 'S';
    swap_map['t'] = 'T';
    swap_map['u'] = 'U';
    swap_map['v'] = 'V';
    swap_map['w'] = 'W';
    swap_map['x'] = 'X';
    swap_map['y'] = 'Y';
    swap_map['z'] = 'Z';

    mirr_map['A'] = 'A';
    mirr_map['E'] = '3';
    mirr_map['H'] = 'H';
    mirr_map['I'] = 'I';
    mirr_map['M'] = 'M';
    mirr_map['O'] = 'O';
    mirr_map['S'] = '2';
    mirr_map['T'] = 'T';
    mirr_map['U'] = 'U';
    mirr_map['V'] = 'V';
    mirr_map['W'] = 'W';
    mirr_map['X'] = 'X';
    mirr_map['Y'] = 'Y';
    mirr_map['Z'] = '5';
    mirr_map['b'] = 'd';
    mirr_map['d'] = 'b';
    mirr_map['i'] = 'i';
    mirr_map['l'] = 'l';
    mirr_map['m'] = 'm';
    mirr_map['n'] = 'n';
    mirr_map['o'] = 'o';
    mirr_map['p'] = 'q';
    mirr_map['q'] = 'p';
    mirr_map['r'] = '7';
    mirr_map['u'] = 'u';
    mirr_map['v'] = 'v';
    mirr_map['w'] = 'w';
    mirr_map['x'] = 'x';
    mirr_map['0'] = '0';
    mirr_map['1'] = '1';
    mirr_map['2'] = 'S';
    mirr_map['3'] = 'E';
    mirr_map['5'] = 'Z';
    mirr_map['7'] = 'r';
    mirr_map['8'] = '8';

    string s, mirror;
    cin >> s;
    int slen = s.length();
    mirror.resize(slen);
    for (int i = 0; i < slen; i++) {
        if (swap_map[s[i]]) {
            s[i] = swap_map[s[i]];
        }
    }
    for (int i = 0; i < slen; i++) {
        if (mirr_map[s[i]]) {
            mirror[slen - i - 1] = mirr_map[s[i]];
        } else {
            cout << "-1\n";
            return 0;
        }
    }

    int bg = -1, ed = -1, qsize = 0;
    bool is_quil = true;
    for (int i = 0; i < slen; i++) {
        if (s[i] == mirr_map[s[0]]) {
            is_quil = true;
            for (int j = 0; j <= (i + 1) / 2; j++) {
                if (s[j] != mirr_map[s[i - j]]) {
                    is_quil = false;
                    break;
                }
            }
            if (is_quil) {
                bg = 0;
                ed = i;
                qsize = i + 1;
            }
        }
    }
    int stidx = slen - 1 - qsize;
    for (int i = stidx; i >= 0; i--) {
        if (s[i] == mirr_map[s[slen-1]]) {
            is_quil = true;
            for (int j = i; j <= (slen - i) / 2; j++) {
                if (s[j] != mirr_map[s[slen + i - 1 - j]]) {
                    is_quil = false;
                    break;
                }
            }
            if (is_quil) {
                bg = i;
                ed = slen - 1;
            }
        }
    }
    qsize = ed - bg + 1;
    int osize = slen - qsize;

    /*
    cout << s << '\n';
    cout << mirror << '\n';
    cout << bg << ' ' << ed << '\n';
    */

    if (bg == 0) {
        cout << mirror.substr(0, osize) + s << '\n';
    } else {
        cout << s + mirror.substr(slen - osize, osize) << '\n';
    }
}