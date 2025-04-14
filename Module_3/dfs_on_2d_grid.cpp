#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int row, cul;

bool valid(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= cul)
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
        int par_row = par.first;
        int par_cul = par.second;
        cout << par_row << " " << par_cul << endl;

        for (int i = 0; i < 4; i++)
        {
            int child_row = par_row + dir[i].first;
            int child_cul = par_cul + dir[i].second;
            if (valid(child_row, child_cul) && !vis[child_row][child_cul])
            {
                q.push({child_row, child_cul});
                vis[child_row][child_cul] = true;
            }
        }
    }
}

int main()
{
    cin >> row >> cul;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < cul; c++)
            cin >> grid[r][c];

    int sr, sc; // source row, source culumn.
    cin >> sr >> sc;
    memset(vis, false, sizeof(vis));
    bfs(sr, sc);

    return 0;
}