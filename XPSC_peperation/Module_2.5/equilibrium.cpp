#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int total_sum = 0;
    vector<int> pre(n);

    pre[0] = v[0];

    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + v[i];

    for (int i = 0; i < n; i++)
        total_sum += pre[i];
    cout<<total_sum<<endl;

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int rightsum = total_sum - pre[mid];
        if (pre[mid] == rightsum)
        {
            cout << pre[mid] << endl;
            return 0;
        }
        else if (pre[mid] > rightsum)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}