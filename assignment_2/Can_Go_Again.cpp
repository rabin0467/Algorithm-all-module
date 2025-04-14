#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b;
    long long w;
    Edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

vector<Edge> edg_list;
int n, e;
long long dis[1005];

bool cycle = false;
void bellman_ford()
{
    for (int i = 1; i < n; i++)
    {
        for (auto ed : edg_list)
        {
            int a, b;
            long long w;
            a = ed.a;
            b = ed.b;
            w = ed.w;
            if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
                dis[b] = dis[a] + w;
        }
    }
    for (auto ed : edg_list)
    {
        int a, b;
        long long w;
        a = ed.a;
        b = ed.b;
        w = ed.w;
        if (dis[a] != LLONG_MAX && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edg_list.push_back(Edge(a, b, w));
    }
    for (long long i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    int src;
    cin >> src;
    dis[src] = 0;
    bellman_ford();
    int tc;
    cin >> tc;
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    else
    {
        while (tc--)
        {
            int dst;
            cin >> dst;
            if (dis[dst] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[dst] << endl;
        }
    }

    return 0;
}