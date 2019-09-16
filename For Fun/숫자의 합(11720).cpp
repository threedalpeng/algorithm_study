#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += (s[i] - '0');
    }
    
    cout << result << endl;
}