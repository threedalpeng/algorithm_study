// IOIOI
#include <iostream>
using namespace std;

int N, M;
string S;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    cin >> S;
    int res = 0;
    for(int i = 0; i < M;)
    {
        if (S[i] == 'I')
        {
            int cnt = 0;
            i++;
            if (i >= M) break;
            while(S[i] == 'O' && S[i + 1] == 'I')
            {
                cnt++;
                i += 2;
                if (i >= M) break;
            }
            int sub_res = cnt - N + 1;
            res += (sub_res > 0 ? sub_res : 0);
        }
        else i++;
    }
    cout << res;
}