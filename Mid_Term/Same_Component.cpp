#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool flag = false;
int r, c;
int sr, sc, dr, dc;
bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}
void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    if (vis[dr][dc])
        flag = true;
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
    cin >> sr >> sc >> dr >> dc;
    dfs(sr, sc);
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}