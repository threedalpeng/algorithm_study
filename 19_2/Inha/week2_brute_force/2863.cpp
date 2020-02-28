// 이게 분수
#include <iostream>
using namespace std;

void rotate(double* T)
{
    double temp = T[0];
    T[0] = T[3];
    T[3] = T[2];
    T[2] = T[1];
    T[1] = temp;
}

int main()
{
    int n_rotate;
    double max = 0.0, T[4];
    cin >> T[0] >> T[1] >> T[3] >> T[2];
    for(int i = 0; i < 4; i++)
    {
        double res = T[0] / T[3] + T[1] / T[2];
        if (res > max)
        {
            max = res;
            n_rotate = i;
        }
        rotate(T);
    }
    cout << n_rotate;
}