#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    while (n--)
    {
        int val;
        cin >> val;
        st.push(val);
    }
    int m;
    cin >> m;
    queue<int> q;
    while (m--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    if (st.size() != q.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    bool flag = true;
    while (!q.empty())
    {
        if (st.top() != q.front())
            flag = false;

        st.pop();
        q.pop();
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}