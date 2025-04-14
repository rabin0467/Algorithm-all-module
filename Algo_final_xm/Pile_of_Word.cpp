#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        bool flag = false;
        if (s.size() != t.size())
        {
            cout << "NO" << endl;
        }
        else
        {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            if (s == t)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}