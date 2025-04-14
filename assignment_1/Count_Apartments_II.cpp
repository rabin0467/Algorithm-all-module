#include <bits/stdc++.h>
using namespace std;

char grid[10005][10005];
bool vis[10005][10005];
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int row, col;

bool valid(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}
int cnt = 0;
void dfs(int sr, int sc)
{
    vis[sr][sc] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int cr = sr + dir[i].first;
        int cc = sc + dir[i].second;
        if (valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] != '#')
        {
            dfs(cr, cc);
        }
    }
}

int main()
{

    cin >> row >> col;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cin >> grid[r][c];
        }
    }

    memset(vis, false, sizeof(vis));

    vector<int> v;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if (grid[r][c] == '.' && !vis[r][c])
            {
                cnt = 0;
                dfs(r, c);
                v.push_back(cnt);
            }
        }
    }
    if (v.empty())
        cout << "0" << endl;
    else
    {
        sort(v.begin(), v.end());
        for (int val : v)
            cout << val << " ";
    }

    return 0;
}