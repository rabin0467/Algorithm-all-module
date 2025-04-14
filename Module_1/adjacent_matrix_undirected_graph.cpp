#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];
    // for(int i = 0;i<n ; i++)
    // {
    //     for(int j = 0; j<n ; j++)
    //     {
    //         adj_mat[i][j] = 0;
    //     }
    // }
    memset(adj_mat, 0, sizeof(adj_mat)); // shortcut way to make all value 0 in a matrix.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                adj_mat[i][j] = 1;
    for (int i = 0; i < e; i++)
    {
        // connection gula input nilam:
        int a, b;
        cin >> a >> b;
        // matrix er value 0 korlam:
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1; // only for undirected graph.
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}