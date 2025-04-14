#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int tetro[n+2];
    tetro[0] = 0;
    tetro[1] = 1;
    tetro[2] = 1;
    tetro[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        tetro[i] = tetro[i - 1] + tetro[i - 2] + tetro[i - 3] + tetro[i - 4];
    }
    cout << tetro[n] << endl;

    return 0;
}