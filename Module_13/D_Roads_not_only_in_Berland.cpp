#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

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
    int n;
    cin >> n;
    int e = n - 1;
    for (int i = 1; i <= n; i++)
    {
        group_size[i] = 1;
        par[i] = -1;
    }
    vector<pair<int, int>> rvm;
    vector<pair<int, int>> create;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leader_a = find(a);
        int leader_b = find(b);
        if (leader_a == leader_b)
        {
            rvm.push_back({a, b});
        }
        else
            dsu_union(a, b);
    }
    for (int i = 2; i <= n; i++)
    {
        int leader_1 = find(1);
        int leader_i = find(i);
        if (leader_1 != leader_i)
        {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << rvm.size() << endl;
    for (int i = 0; i < rvm.size(); i++)
        cout << rvm[i].first << " " << rvm[i].second << " " << create[i].first << " " << create[i].second << endl;

    return 0;
}