#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
bool vis[1005][1005];
int dis[1005][1005];
pair<int, int> parent[1005][1005];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    dis[sr][sc] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_r = par.first;
        int par_c = par.second;
        for (int i = 0; i < 4; i++)
        {
            int cr = par_r + d[i].first;
            int cc = par_c + d[i].second;
            if (valid(cr, cc) && !vis[cr][cc] && (grid[cr][cc] == '.' || grid[cr][cc] == 'A' || grid[cr][cc] == 'B'))
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
                dis[cr][cc] = dis[par_r][par_c] + 1;
                parent[cr][cc] = {par_r, par_c};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int sr, sc, dr, dc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'B')
            {
                dr = i;
                dc = j;
            }
        }
    }
    memset(dis, -1, sizeof(dis));
    memset(vis, false, sizeof(vis));
    bfs(sr, sc);
    vector<char> path;
    if (vis[dr][dc])
    {
        cout << "YES" << endl;
        cout << dis[dr][dc] << endl;
        int cr = dr;
        int cc = dc;
        while (1)
        {
            if (grid[cr][cc] == 'A')
                break;
            pair<int, int> par = parent[cr][cc];
            int p_r = par.first;
            int p_c = par.second;
            if (p_r - cr == -1 && p_c - cc == 0)
                path.push_back('D');
            if (p_r - cr == 1 && p_c - cc == 0)
                path.push_back('U');
            if (p_c - cc == -1 && p_r - cr == 0)
                path.push_back('R');
            if (p_c - cc == 1 && p_r - cr == 0)
                path.push_back('L');
            cr = p_r;
            cc = p_c;
        }
        reverse(path.begin(), path.end());
        for (char c : path)
            cout << c;
        cout << endl;
    }

    else
        cout << "NO" << endl;

    return 0;
}