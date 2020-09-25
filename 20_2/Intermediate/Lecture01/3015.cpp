// 오아시스 재결합
#include <iostream>
#include <stack>
using namespace std;
using pii = pair<int, int>;

int N, p;
stack<pii> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cin >> p;
    s.push({p, 1});
    int cnt = 0;
    for (int i = 1; i < N; i++)
    {
        int n_push = 1;
        cin >> p;
        do
        {
            ++cnt;
            if (s.top().first < p)
            {
                s.pop();
            }
            else if (s.top().first == p)
            {
                n_push += s.top().second;
                cnt += s.top().second;
                s.pop();
            }
            else
                break;
        } while (!s.empty());
        s.push({p, n_push});
        cout << cnt << '\n';
    }
    cout << cnt << '\n';
}