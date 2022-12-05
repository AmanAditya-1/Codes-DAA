#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y)
{
    int m = x.length(), n = y.length();
    int l[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                l[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                l[i][j] = 1 + l[i - 1][j - 1];

            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }
    return l[m][n];
}

int main()
{
    string s1 = "tiles";
    string s2 = "millets";
    cout << "LCS= " << lcs(s1, s2) << endl;

    return 0;
}