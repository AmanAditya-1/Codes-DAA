#include <bits/stdc++.h>
using namespace std;
int max_profit(vector<vector<int>> elements, int m)
{
    sort(elements.begin(), elements.end());
    vector<vector<int>> v(elements.size() + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= elements.size(); i++)
    {
        for (int w = 1; w <= m; w++)
        {
            if (w - elements[i - 1][1] >= 0)
            {
                v[i][w] = max(v[i - 1][w], v[i - 1][w - elements[i - 1][1]] + elements[i - 1][0]);
            }
            else
            {
                v[i][w] = v[i - 1][w];
            }
        }
    }
    return v[elements.size()][m];
}
int main()
{
    vector<vector<int>> elements = {
        // profit,weight
        {3, 2},
        {5, 3},
        {6, 4},
        {10, 5}};
    int m = 8;
    cout << "Maximum Profit = " << max_profit(elements, m);
    return 0;
}
