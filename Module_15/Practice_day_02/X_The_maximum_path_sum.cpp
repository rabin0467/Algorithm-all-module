#include <bits/stdc++.h>
using namespace std;
int val[100005][100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> val[i][j];
    return 0;
}