// 잃어버린 괄호
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string s_input;
    cin >> s_input;

    s_input += 'z'; // for indicating an end of a string;

    int num = 0;
    int result = 0;

    int i = 0;
    for(i; i < s_input.length(); i++)
    {
        if (isdigit(s_input[i]))
        {
            num = num * 10 + (s_input[i] - '0');
        }
        else
        {
            result += num;
            num = 0;
            if (s_input[i] == '-')
            {
                break;
            }
        }
    }

    for(i; i < s_input.length(); i++)
    {
        if (isdigit(s_input[i]))
        {
            num = num * 10 + (s_input[i] - '0');
        }
        else
        {
            result -= num;
            num = 0;
        }
    }

    cout << result << endl;
}