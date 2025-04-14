#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, q;
    cin >> n >> q;
    vector<long long> v;
    for (int i = 1; i <= n / 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            v.push_back(i);
        }
    }
    vector<long long> pre(n);
    pre[0] = v[0];
    for (int i = 1; i < v.size(); i++)
        pre[i] = pre[i - 1] + v[i];

    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        if (l > 1)
            cout << pre[r - 1] - pre[l - 2] << endl;
        else
            cout << pre[r - 1] << endl;
    }
    return 0;
}