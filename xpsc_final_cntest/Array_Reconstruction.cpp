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
        int n;
        cin >> n;
        vector<int> v(n - 2);
        for (int i = 0; i < n - 2; i++)
            cin >> v[i];
        long long total_sum;
        cin >> total_sum;
        long long cur_sum = 0;
        for (int i = 0; i < n - 2; i++)
            cur_sum += v[i];
        long long nmbr = total_sum - cur_sum;
        if (nmbr >= 0)
            cout << nmbr + 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}