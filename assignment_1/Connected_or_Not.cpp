#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000005];
bool vis[1000005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
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
    }
    memset(vis, false, sizeof(vis));

    int q;
    cin >> q;
    while (q--)
    {
        int flag = 0;

        int src, dst;
        cin >> src >> dst;
        if (src == dst)
        {
            cout << "YES" << endl;
            continue;
        }

        bfs(src);

        for (int val : adj_list[src])
        {

            if (val == dst)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}