// 알파벳 찾기
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    int n;
    cin >> S;
    for (char c = 'a'; c <= 'z'; c++)
        cout << ((n = S.find(c)) == string::npos ? -1 : n) << ' ';
}