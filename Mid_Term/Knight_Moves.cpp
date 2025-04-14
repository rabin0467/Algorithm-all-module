#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
int r, c;
bool valid(int i, int j)
{
    if (i < 0 || i >= r || j < 0 || j >= c)
        return false;
    return true;
}
void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    level[sr][sc] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_r = par.first;
        int par_c = par.second;
        for (int i = 0; i < 8; i++)
        {
            int cr = par_r + d[i].first;
            int cc = par_c + d[i].second;
            if (valid(cr, cc) && !vis[cr][cc])
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
                level[cr][cc] = level[par_r][par_c] + 1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> r >> c;
        int sr, sc, dr, dc;
        cin >> sr >> sc >> dr >> dc;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(sr, sc);
        cout << level[dr][dc] << endl;
    }
    return 0;
}