#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int dis[100005];
int parent[100005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 1;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
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

    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    int dst = n;
    vector<int> path;
    bfs(1);
    if (!vis[n])
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << dis[n] << endl;
        while (dst != -1)
        {
            path.push_back(dst);
            dst = parent[dst];
        }
        reverse(path.begin(), path.end());
        for (int val : path)
            cout << val << " ";
    }
    return 0;
}