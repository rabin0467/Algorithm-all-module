#include<bits/stdc++.h>
using namespace std;
vector<int> dp(10005, -1); 
bool if_yes(long long curr, long long n) {
    if (curr == n) {
        return true;
    }
    if (curr > n) { 
        return false;
    }

    if (dp[curr] != -1) {
        return dp[curr]; 
    }
    dp[curr] = if_yes(curr + 3, n) || if_yes(curr + 4, n);
    
    return dp[curr];
}

int main() {
    long long n;
    cin >> n;
    if (if_yes(0, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}