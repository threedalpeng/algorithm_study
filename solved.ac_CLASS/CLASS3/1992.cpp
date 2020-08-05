// 쿼드트리
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<string> vs;

string divide(int x, int y, int n)
{
    if (n == 1) return vs[x].substr(y, 1);
    n /= 2;
    string s1 = divide(x, y, n);
    string s2 = divide(x, y + n, n);
    string s3 = divide(x + n, y, n);
    string s4 = divide(x + n, y + n, n);
    if (s1.length() == 1 && s1 == s2 && s2 == s3 && s3 == s4)
        return s1;
    else
        return "("s + s1 + s2 + s3 + s4 + ")"s;
}

int main()
{
    cin >> N;
    string si, res = "";
    for (int i = 0; i < N; i++)
    {
        cin >> si;
        vs.push_back(si);
    }
    cout << divide(0, 0, N);
}