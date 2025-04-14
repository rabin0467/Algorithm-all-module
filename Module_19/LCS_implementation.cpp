#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[1005][1005];
int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else
    {
        int op1 = lcs(i - 1, j);
        int op2 = lcs(i, j - 1);
        return dp[i][j] = max(op1, op2);
    }
}
int main()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    cout << lcs(n - 1, m - 1) << endl;

    return 0;
}