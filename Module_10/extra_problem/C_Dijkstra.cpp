#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

vector<Edge> edge_list;
int dis[1000005];
int n, e;
vector<int> parent(1000005, -1);
void bellman_ford()
{
    for (int i = 1; i < n; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int w = ed.w;
            if (dis[a] != INT_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
                parent[b] = a;
            }
        }
    }
}

int main()
{

    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
        edge_list.push_back(Edge(b, a, w));
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;

    dis[1] = 0;
    

    bellman_ford();

    for (int i = 1; i <= n; i++)
        if(parent[i] != -1)
            cout << parent[i] << " ";
    return 0;
}