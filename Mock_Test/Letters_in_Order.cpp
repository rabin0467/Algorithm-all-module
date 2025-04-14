#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    set<char> st;
    for (char c : s)
        st.insert(c);

    for (auto it = st.begin(); it != st.end(); it++)
        cout << *it;
    return 0;
}