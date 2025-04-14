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
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), greater<int>());
        int sum_1 = 0;
        int sum_2 = 0;
        for (int val : v)
        {
            if (sum_1 <= sum_2)
                sum_1 += val;
            else
                sum_2 += val;
        }
        cout << abs(sum_1 - sum_2) << endl;
    }
    return 0;
}