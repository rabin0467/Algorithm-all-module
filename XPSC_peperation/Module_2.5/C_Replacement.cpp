#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 5);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int &val : v)
    {
        if (val > 0)
            val = 1;
        else if (val < 0)
            val = 2;
    }
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}