#include <bits/stdc++.h>
using namespace std;
int dp[100005];
bool knapsack(int i, int mx)
{
    if (i == mx)
        return  true;

    if (i > mx)
        return  false;

    if (dp[i] != -1)
        return dp[i];

    dp[i] = knapsack(i + 3, mx) || knapsack(i * 2, mx);
    return dp[i];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int mx;
        cin >> mx;
        memset(dp, -1, sizeof(dp));
        bool flag = knapsack(1, mx);

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}