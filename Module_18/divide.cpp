#include <bits/stdc++.h>
using namespace std;
vector<int> a(1005);

void divide(int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << a[i] << " ";
    cout << endl;
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    divide(l, mid);
    divide(mid + 1, r);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    divide(0, n - 1);
    return 0;
}