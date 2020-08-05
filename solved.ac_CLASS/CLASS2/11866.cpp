// 요세푸스 문제 0
#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    for (int i = 1; i <= K - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
    cout << "<" << q.front();
    q.pop();
    while(!q.empty())
    {
        for (int i = 1; i <= K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << ", " << q.front();
        q.pop();
    }
    cout << ">";
}