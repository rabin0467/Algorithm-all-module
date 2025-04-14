#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> pre(n+1,0);
   
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + v[i-1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        
        cout << pre[r] - pre[l-1] << endl;
    }

    return 0;
}