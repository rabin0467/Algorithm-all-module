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
        vector<int> v(n + 5);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int mx1 = -1, mx2 = -1;

        int idx1 = -1, idx2 = -1;

        for (int i = 0; i < n; i++)
        {
            if (v[i] >= mx1)
            {
                mx2 = mx1;
                idx2 = idx1;
                mx1 = v[i];
                idx1 = i;
            }
            else if (v[i] >= mx2 && v[i] < mx1)
            {
                mx2 = v[i];
                idx2 = i;
            }
        }
        cout << min(idx1, idx2) << " " << max(idx1, idx2) << endl;
    }
    return 0;
}