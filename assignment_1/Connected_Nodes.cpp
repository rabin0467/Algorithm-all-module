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
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));

    int q;
    cin >> q;
    while (q--)
    {
        int src;
        cin >> src;
        bfs(src);

        vector<int> v;

        if (adj_list[src].empty())
        {
            cout << "-1";
        }
        else
        {
            for (int val : adj_list[src])
            {
                v.push_back(val);
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int val : v)
        {
            if (v.empty())
                cout << "-1" << endl;
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}