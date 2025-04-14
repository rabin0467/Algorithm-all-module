#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        int thief = -1;
        for (auto x : mp)
        {
            if (x.second % 2 != 0)
            {
                thief = x.first;
                break;
            }
        }
        cout << thief << endl;
    }
    return 0;
}