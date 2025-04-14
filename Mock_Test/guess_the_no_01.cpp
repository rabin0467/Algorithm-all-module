#include <bits/stdc++.h>
using namespace std;
vector<int> dp(10005, -1);
bool knapsack(int i, int mx)
{
    if (i == mx)
        return true;
    if (i > mx)
        return false;
    if (dp[i] != -1)
        return dp[i];

    bool op = knapsack(i + 3, mx) || knapsack(i + 4, mx);
    dp[i] = op;
    return dp[i];
}
int main()
{
    long long n;
    cin >> n;

    bool flag = knapsack(0, n);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
