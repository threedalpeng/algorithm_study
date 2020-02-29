// 프린터 큐
#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int T, N, M, prior, cnt;

int main()
{
    cin >> T;
    while(T--)
    {
        queue<pii> q;
        priority_queue<int> pq;
        cin >> N >> M;
        for (int j = 0; j < N; j++)
        {
            cin >> prior;
            q.push({j, prior});
            pq.push(prior);
        }
        cnt = 0;
        while(!q.empty())
        {
            while(pq.top() != q.front().second)
            {
                q.push(q.front());
                q.pop();
            }
            if (q.front().first == M)
            {
                cnt++;
                break;
            }
            pq.pop(); q.pop(); cnt++;
        }
        cout << cnt << '\n';
    }
}