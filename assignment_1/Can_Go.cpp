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
    int sr = -1; // sourde row, source column
    int sc = -1;
    int dr = -1; // destination row, destination column.
    int dc = -1;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> grid[r][c];
        }
    }
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (grid[r][c] == 'A')
            {
                sr = r;
                sc = c;
            }
            if (grid[r][c] == 'B')
            {
                dr = r;
                dc = c;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(sr, sc);

    if (vis[dr][dc] == true)
        cout << "YES" << endl;

    else
        cout << "NO" << endl;
    return 0;
}