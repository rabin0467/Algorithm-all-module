#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;
int cnt;
bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}
void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int cr = sr + d[i].first;
        int cc = sc + d[i].second;
        if (valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == '.')
            dfs(cr, cc);
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    memset(vis, false, sizeof(vis));
    cnt = 0;
    int mn = INT_MAX;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(cnt, mn);
            }
        }
    }
    if (mn == INT_MAX)
        cout << "-1" << endl;
    else
        cout << mn << endl;

    return 0;
}