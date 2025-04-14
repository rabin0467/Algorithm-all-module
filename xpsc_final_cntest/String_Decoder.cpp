#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        vector<char> v;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i += 2)
        {
            char c = s[i];
            int cnt = s[i + 1] - '0';
            while (cnt--)
            {
                v.push_back(c);
            }
        }
        for (char ch : v)
            cout << ch;
        cout << endl;
    }

    return 0;
}