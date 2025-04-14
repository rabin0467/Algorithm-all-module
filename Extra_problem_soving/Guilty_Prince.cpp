#include <bits/stdc++.h>
using namespace std;
char grid[25][25];
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vis[25][25];
int col, row;
int cnt;
bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int cr = si + d[i].first;
        int cc = sj + d[i].second;
        if (valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == '.')
            dfs(cr, cc);
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {

        cin >> col >> row;
        int src_i, src_j;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '@')
                {
                    src_i = i;
                    src_j = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        // memset(valid, false, sizeof(valid));
        cnt = 0;
        dfs(src_i, src_j);
        cout << "Case" << " " << i << ":" << " " << cnt << endl;
    }

    return 0;
}