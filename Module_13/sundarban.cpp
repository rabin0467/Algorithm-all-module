#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    return true;
}

int cnt;

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
        int par_row = par.first;
        int par_col = par.second;
        for (int i = 0; i < 4; i++)
        {
            int child_row = par_row + d[i].first;
            int child_col = par_col + d[i].second;
            if (valid(child_row, child_col) && !vis[child_row][child_col] && grid[child_row][child_col] != 'T')
            {
                q.push({child_row, child_col});
                vis[child_row][child_col] = true;
                level[child_row][child_col] = level[par_row][par_col] + 1;
            }
        }
    }
}

int main()
{

    while (cin >> n)
    {
        int sr, sc, dr, dc;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }
                if (grid[i][j] == 'E')
                {
                    dr = i;
                    dc = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));

        bfs(sr, sc);

        cout << level[dr][dc] << endl;
    }

    return 0;
}