#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];

int unbound_knapsack(int i, int mx)
{
    if (i < 0 || mx <= 0)
        return 0;
    if (dp[i][mx] != -1)
        return dp[i][mx];
    if (weight[i] <= mx)
    {
        int op1 = unbound_knapsack(i, mx - weight[i]) + val[i];
        int op2 = unbound_knapsack(i - 1, mx);
        dp[i][mx] = max(op1, op2);
        return dp[i][mx];
    }
    else
        return unbound_knapsack(i - 1, mx);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int mx_weight;
    cin >> mx_weight;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;
    cout << unbound_knapsack(n - 1, mx_weight) << endl;
    return 0;
}