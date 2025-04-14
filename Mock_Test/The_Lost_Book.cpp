#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int b;
    cin >> b;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == b)
        {
            idx = i;
            break;
        }
        }
    cout << idx << endl;
    return 0;
}