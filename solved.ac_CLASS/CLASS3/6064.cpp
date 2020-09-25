#include <iostream>
using namespace std;

int T, M, N, X, Y;

int gcd(int a, int b) 
{
    int c;
    while(b) 
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> M >> N >> X >> Y;
        int start = X % N;
        if (!start) start = N;
        int count = M % N;
        bool found = false;
        int cur = start;
        for (int i = 0; i < N / (M > N ? gcd(M, N) : gcd(N, M)); i++)
        {
            if (Y == cur)
            {
                found = true;
                cout << X + i * M << '\n';
                break;
            }
            cur = (cur + count) % N;
            if (!cur) cur = N;
        }
        if (!found) cout << -1 << '\n';
    }
}