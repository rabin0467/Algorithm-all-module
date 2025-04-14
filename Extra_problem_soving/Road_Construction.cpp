#include <bits/stdc++.h>
using namespace std;

int par[100005];
int group_size[100005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
int mx_group_size = 1;
void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader1] = group_size[leader2])
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
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));
    int n, e;
    cin >> n >> e;
    int component = n;
    mx_group_size = 1;
    int sz = 0;
    while (e--)
    {
        int a, b;
        cin>>a>>b;
        int leader_a = find(a);
        int leader_b = find(b);
        
        if (leader_a != leader_b)
        {
            dsu_union(a, b);
            component--;
            
        }
        cout << component << " " << sz << endl;
    }
    return 0;
}