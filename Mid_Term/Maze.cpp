#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
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
            if (valid(cr, cc) && !vis[cr][cc] && (grid[cr][cc] == '.' || grid[cr][cc] == 'R' || grid[cr][cc] == 'D'))
            {
                q.push({cr, cc});
                vis[cr][cc] = true;
                parent[cr][cc] = {par_r, par_c};
            }
        }
    }
}
int main()
{
    cin >> r >> c;
    int sr, sc, dr, dc;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'D')
            {
                dr = i;
                dc = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            parent[i][j] = {-1, -1};
    bfs(sr, sc);
    int x = dr, y = dc;

    while (1)
    {
        pair<int,int> par = parent[x][y];
        x = par.first;
        y = par.second;
        if(x== -1 || y == -1)
            break;
        if(grid[x][y] == 'D')
            break;
        if(grid[x][y] == 'R')
            continue;
        grid[x][y]= 'X';
    }


    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}