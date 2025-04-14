#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l;
    int t;
    cin >> t;
    while (t--)
    {
        int idx, val;
        cin >> idx >> val;
        if (idx == 0)
            l.push_front(val);
        else if (idx > l.size())
        {
            cout << "Invalid" << endl;
            continue;
        }

        else if (idx  == l.size())
        {
            l.push_back(val);
        }
        else
        {
            l.insert(next(l.begin(), idx), val);
        }
        for (int x : l)
            cout << x << " ";
        cout << endl;

        l.reverse();
        for (int x : l)
            cout << x << " ";

        cout << endl;
        l.reverse();
    }
    return 0;
}