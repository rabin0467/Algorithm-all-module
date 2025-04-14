#include <bits/stdc++.h>
using namespace std;
vector<int> c(1005);

void conquer(int l, int mid, int r)
{
    int n = mid - l + 1;
    vector<int> a(n);
    int k = l;
    for (int i = 0; i < n; i++, k++)
        a[i] = c[k];
    int m = r - mid;
    vector<int> b(m);
    k = mid + 1;
    for (int i = 0; i < m; i++)
        b[i] = c[k];

    int i = 0, j = 0, curr = l;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            c[curr++] = a[i++];
        else
            c[curr++] = b[j++];
    }
    while (i < n)
        c[curr++] = a[i++];
    while (j < m)
        c[curr++] = b[j++];
}

void divide(int l, int r)
{

    if (l >= r)
        return;
    int mid = (l + r) / 2;
    divide(l, mid);
    divide(mid + 1, r);
    conquer(l, mid, r);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    divide(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    return 0;
}