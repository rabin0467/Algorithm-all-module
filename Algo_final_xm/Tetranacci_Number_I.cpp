#include <bits/stdc++.h>
using namespace std;
int dp[1005];
int tetro(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = tetro(n - 1) + tetro(n - 2) + tetro(n - 3) + tetro(n - 4);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << tetro(n) << endl;
    return 0;
}