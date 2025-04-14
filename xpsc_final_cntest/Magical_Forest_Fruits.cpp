#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += a[i];
        }
        cout << sum << endl;
    }

    return 0;
}