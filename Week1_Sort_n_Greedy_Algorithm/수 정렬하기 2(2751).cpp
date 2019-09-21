#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    int input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for(auto i : v)
    {
        cout << i << '\n';
    }
    return 0;
}