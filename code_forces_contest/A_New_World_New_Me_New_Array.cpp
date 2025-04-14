#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p;
        cin >> n >> k >> p;
        int cur_sum = 0;
        int cnt = 0;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
            cur_sum += arr[i];
        }

        int change = k - cur_sum;
        for (int i = 0; i < p; i++)
        {
            if (change > 0)
            {
                arr[i] += change;
            }
            else
                arr[i] -= change;
        }

        int new_sum = 0;
        for (int i = 0; i < n; i++)
        {
            new_sum += arr[i];
            cnt++;
        }

        if (new_sum != k)
            cout << "-1" << endl;
        else
            cout << cnt << endl;
    }
    return 0;
}