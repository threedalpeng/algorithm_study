// 카드2
#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> cards;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cards.push_back(i);
    while(cards.size() != 1)
    {
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }
    cout << cards.front();
}