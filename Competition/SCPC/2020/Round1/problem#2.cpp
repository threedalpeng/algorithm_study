#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

vector<int> X, Y;
vector<vector<bool>> Win;
set<pii> prv, nxt;

inline bool onRange(int x, int y, int n)
{
    return (x <= n) && (y <= n);
}

void print_vec2x2(vector<vector<bool>> Win)
{
    for (auto v : Win)
    {
        for (auto i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(int argc, char **argv)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, test_case, n, k;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> n >> k;

        X.resize(n + 1, 0);
        Y.resize(n + 1, 0);
        Win.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            Win[i].resize(n + 1);
            fill(Win[i].begin(), Win[i].end(), false);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> X[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> Y[i];
        }

        Win[0][0] = true;
        Win[0][1] = false;
        Win[1][0] = false;
        prv.insert({0, 1});
        prv.insert({1, 0});
        int count_win = 1;
        print_vec2x2(Win);
        while (!prv.empty())
        {
            for (auto p : prv)
            {
                int x0 = p.first, y0 = p.second;
                int x = x0, y = y0;
                int dx = 0, dy = 0;
                while (++x <= n && (dx += X[x]) <= k)
                    Win[x][y0] == true;
                if (x + 1 <= n)
                    nxt.insert({x + 1, y0});
                if (y0 + 1 <= n)
                    nxt.insert({x, y0 + 1});
                while (++y <= n && (dy += Y[y]) <= k)
                    Win[x0][y] == true;
                if (x0 + 1 <= n)
                    nxt.insert({x0 + 1, y});
                if (y + 1 <= n)
                    nxt.insert({x0, y + 1});
            }
            for (auto p : nxt)
            {
                if ()
            }
            // print_vec2x2(Win);
            cout << '\n';
            prv = nxt;
            nxt.clear();
        }

        cout << "Case #" << test_case + 1 << '\n';
        cout << count_win << ' ' << (n + 1) * (n + 1) - count_win << '\n';
    }

    return 0;
}