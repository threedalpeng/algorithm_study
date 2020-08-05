// Z
#include <iostream>
using namespace std;

int N, r, c;
int pwr[16] = {
    1,      2,      4,      8,      
    16,     32,     64,     128,    
    256,    512,    1024,   2048,   
    4096,   8192,   16384,  32768
};

int divide(int n, int r, int c)
{
    int x = (r / pwr[n - 1]);
    int y = (c / pwr[n - 1]);
    if (n == 1) return 2 * x + y;
    return (2 * x + y) * pwr[n - 1] * pwr[n - 1] + divide(n-1, r-x*pwr[n-1], c-y*pwr[n-1]);
}

int main()
{
    cin >> N >> r >> c;
    cout << divide(N, r, c);
}