// 제로
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int k, num, sum;
vector<int> v;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> num;
        if (num == 0)
        {
            sum -= v.back();
            v.pop_back();
        }
        else
        {
            sum += num;
            v.push_back(num);
        }
    }
    cout << sum;
}