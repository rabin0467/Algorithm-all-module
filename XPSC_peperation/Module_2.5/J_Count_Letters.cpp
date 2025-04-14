#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int freq[26] = {};
    for (int i = 0; i < s.size(); i++)
    {
        int cnt = s[i] - 'a';
        freq[cnt]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            char c = i + 'a';
            cout << c << " " << ":" << " " << freq[i] << endl;
        }
    }

    return 0;
}