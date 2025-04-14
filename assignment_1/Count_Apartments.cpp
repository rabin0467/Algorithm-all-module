#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int row, col;

bool valid(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    for (int i = 0; i < 4; i++)
    {
        int cr = sr + dir[i].first;
        int cc = sc + dir[i].second;
        if (valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] != '#')
        {
            dfs(cr, cc);
            vis[cr][cc] = true;
        }
    }
}

int main()
{

    cin >> row >> col;
    int sr = -1;
    int sc = -1;
    int dr = -1;
    int dc = -1;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> grid[r][c];
        }
    }

    memset(vis, false, sizeof(vis));
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '.')
            {
                if (!vis[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
    }
    cout << cnt << endl;

    return 0;
}