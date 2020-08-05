// Passport Control
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;
    int count = 0;
    list<int> l;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        l.push_back(num);
    }

    while(!l.empty())
    {
        auto it = l.begin();
        int min = 0;
        while(it != l.end())
        {
            if((*it) > min)
            {
                min = (*it);
                it = l.erase(it);
            }
            else
            {
                ++it;
            }
        }
        ++count;
    }

    cout << (count <= k ? "YES" : "NO") << endl;
}