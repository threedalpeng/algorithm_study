// 달팽이는 올라가고 싶다
#include <iostream>
using namespace std;

int a, b, v;

int main()
{
    cin >> a >> b >> v;
    cout << (v - a) / (a - b) + 1 + ((v - a) % (a - b) ? 1 : 0); 
}