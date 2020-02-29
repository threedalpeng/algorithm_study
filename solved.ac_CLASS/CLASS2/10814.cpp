// 나이순 정렬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct P { int age; string name; };
int n;
P p[100001];

bool cmp( P p1, P p2 ) { return p1.age < p2.age; }

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].age >> p[i].name;
    }
    stable_sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << p[i].age << ' ' << p[i].name << '\n';
    }
}