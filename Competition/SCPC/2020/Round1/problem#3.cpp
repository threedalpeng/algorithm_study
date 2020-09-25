#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

int main(int argc, char** argv)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T, test_case, N, k, m, b, e;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> k >> m;
        joint.resize(k);
        for (auto j : joint)
            cin >> j;

        for (int i = 0; i < m; i++)
        {
            cin >> b >> e;
        }
        cout << "Case #" << test_case + 1 << endl;
    }

    return 0;
}