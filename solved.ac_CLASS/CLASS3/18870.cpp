#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, x;
map<int, int> normalized;
vector<int> X, sortedX;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        X.push_back(x);
    }
    sortedX.assign(X.cbegin(), X.cend());
    sort(sortedX.begin(), sortedX.end());
    int prv = 1e9+1, cnt = 0;
    for (auto i : sortedX)
    {
        if (i != prv)
        {
            prv = i;
            normalized[i] = cnt++;
        }
    }
    for (auto i : X)
    {
        cout << normalized[i] << ' ';
    }
}