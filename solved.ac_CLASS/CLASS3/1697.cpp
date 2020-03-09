// 숨바꼭질
#include <iostream>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int N, K;
bool check[100'001];
queue<pii> q;

void qpush(pii i)
{
    if (0 <= i.first && i.first <= 100'000 && !check[i.first]) q.push(i);
}

int main()
{
    cin >> N >> K;
    q.push({N, 0});
    pii front = q.front();
    if (front.first != K)
    {
        while(!q.empty())
        {
            front = q.front();
            q.pop();
            if (front.first == K) break;
            check[front.first] = true;
            qpush({front.first + 1, front.second + 1});
            qpush({front.first - 1, front.second + 1});
            qpush({front.first * 2, front.second + 1});
        }
    }
    cout << front.second;
}