#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[105];
vector<pair<int, int>> d;
bool vis[105];
int cnt;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    d.push_back({src, 0});
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[src])
        {
            if (vis[child])
            {
                q.push(child);
                vis[child] = true;
                d.push_back({child, })
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, e;
        cin >> n >> e;
        while (e--)
        {
            int a, b;
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        int src, dst;
        cin >> src >> dst;
        bfs(src);
    }
    return 0;
}