#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> profit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<pair<double, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        double ratio = ((profit[i] * 1.0) / weight[i]);
        v.push_back({ratio, {profit[i], weight[i]}});
    }
    sort(v.begin(), v.end());
    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (m > 0 && m - v[i].second.second >= 0)
        {
            m -= v[i].second.second;
            ans += v[i].second.first;
        }
        else
        {
            ans += m * v[i].first;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}