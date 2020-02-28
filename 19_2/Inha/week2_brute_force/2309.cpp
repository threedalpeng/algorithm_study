// 일곱 난쟁이
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[9], sum = 0;
    for(int i = 0; i < 9; i++)
    { 
        cin >> A[i];
        sum += A[i];
    }
    sort(A, A + 9);
    int i1, i2;
    for(int i = 0; i < 9; i++)
    {
        bool flag = false;
        for(int j = i + 1; j < 9; j++)
        {
            if(sum - A[i] - A[j] == 100)
            {
                i1 = i, i2 = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    for(int i = 0; i < 9; i++)
    {
        if(i != i1 && i != i2) cout << A[i] << '\n';
    }
}