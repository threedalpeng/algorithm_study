#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX_LENGTH = 2000;

/* Using Dynamic Programming */
// Time complexity: O(n^2)
bool substr[MAX_LENGTH][MAX_LENGTH];

string findPalindrome(string s, int len) {
    int max_len = 1;
    string max_sub = s.substr(0, 1);

    // [i](single character) is always palindrome.
    for (int i = 0; i < len; i++)
        substr[i][i] = true;

    // The substring[i, i+1] is palindrome if [i] == [i+1].
    for (int i = 0; i < len - 1; i++)
        if (s[i] == s[i + 1]) {
            if (max_len < 2) {
                max_len = 2;
                max_sub = s.substr(i, 2);
            }
            substr[i][i + 1] = true;
        }

    // The substring[i, j] is palindrome if [i] == [j] and [i+1, j-1] is palindrome.
    for (int k = 2; k <= len - 1; k++) {
        for (int i = 0; i < len - k; i++) {
            int j = i + k;
            if (s[i] == s[j] && substr[i + 1][j - 1]) {
                if (max_len < k + 1) {
                    max_len = k + 1;
                    max_sub = s.substr(i, max_len);
                }
                substr[i][j] = true;
            }
        }
    }

    return max_sub;
}

/* Manacher's Algorithm */
// Time complexity: O(n)
int radius[2 * MAX_LENGTH + 1];

string manacher(string s, int len) {
    // Preprocess a string by inserting dummy characters(#)
    // to check even-length palindromic strings.
    string tmp = "#";
    for (int i = 0; i < len; i++) {
        tmp += s[i];
        tmp += '#';
    }
    len = len * 2 + 1;

    int range = 0, center = 0, left, right;
    for (int i = 0; i < len; i++) {
        if (i <= range)
            radius[i] = min(radius[2 * center - i], range - i);
        else
            radius[i] = 0;
        left = i - radius[i], right = i + radius[i];
        while (0 <= --left && ++right <= len - 1 && tmp[left] == tmp[right])
            ++radius[i];

        if (range < i + radius[i]) {
            range = i + radius[i];
            center = i;
        }
    }

    int max_radius = 0;
    int max_center = 0;
    for (int i = 0; i < len; i++) {
        if (max_radius < radius[i]) {
            max_radius = radius[i];
            max_center = i;
        }
    }
    int start_idx = (max_center - max_radius) / 2;
    int sub_len = max_radius;

    return s.substr(start_idx, sub_len);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    cout << "Checking whether a substring is palindrome\n";
    cout << "and find the largest palindromic substring.\n";
    cout << "A string to check:\n\t";
    cin >> str;
    cout << "\nUsing DP:\n\t"
         << findPalindrome(str, str.length()) << "\n\n";
    cout << "Using Manacher's Algorithm:\n\t"
         << manacher(str, str.length());
}