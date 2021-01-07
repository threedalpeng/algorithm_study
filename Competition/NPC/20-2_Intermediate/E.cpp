#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<pii> cube;
vector<int> nreq;

int main()
{
    int l, w, h, n, a, b;

    cin >> l >> w >> h;
    cin >> n;
    cube.resize(n + 1);
    nreq.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cube[a] = {static_cast<int>(pow(2, a)), b};
    }
    
    int mn = min(l, min(w, h)), mni = 1;
    while(mn >>= 1) mni <<= 1;
    
    int ln = l / mni, wn = w / mni, hn = h / mni;
    int lr = l % mni, wr = w % mni, hr = h % mni;
    
}