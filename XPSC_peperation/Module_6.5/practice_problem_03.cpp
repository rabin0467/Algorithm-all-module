#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l;
    int val;
    while (1)
    {
        cin >> val;
        if (val == -1)
            break;
        l.push_back(val);
    }
    bool palindrome = true;
    vector<int> v;
    for (int x : l)
        v.push_back(x);

    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
    {
        if (v[i] != v[j])
        {
            palindrome = false;
            break;
        }
    }
    if (palindrome)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}