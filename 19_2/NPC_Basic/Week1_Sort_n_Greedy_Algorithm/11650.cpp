// 좌표 정렬하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;

bool compare(p p1, p p2)
{
    if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<p> v;
    int n1, n2;
    for (int i =0; i<N; i++)
    {
        cin >> n1 >> n2;
        v.push_back({n1, n2});
    }
    sort(v.begin(), v.end(), compare);

    for (int i = 0 ; i < N; i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}