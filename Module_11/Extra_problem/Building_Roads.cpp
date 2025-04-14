#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];

void dsu_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}
int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int par_a = find(a);
        int par_b = find(b);
        if (par_a != par_b)
            dsu_union(a, b);
    }
    int cnt = 0;
    vector<int> ans;
    for (int node = 1; node <= n; node++)
    {
        int par_1 = find(1);
        int par_node = find(node);
        if (par_1 != par_node)
        {
            cnt++;
            dsu_union(1, node);
            ans.push_back(node);
        }
    }
    cout << cnt << endl;
    for (auto it : ans)
        cout << 1 << " " << it << endl;

    return 0;
}