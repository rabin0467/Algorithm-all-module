#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> st1;
    while (n--)
    {
        int val;
        cin >> val;
        st1.push(val);
    }

    int m;
    cin >> m;
    stack<int> st2;
    while (m--)
    {
        int val;
        cin >> val;
        st2.push(val);
    }
    if (st1.size() != st2.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> v1, v2;

    while (!st1.empty())
    {
        v1.push_back(st1.top());
        st1.pop();
        v2.push_back(st2.top());
        st2.pop();
    }
    bool flag = true;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}