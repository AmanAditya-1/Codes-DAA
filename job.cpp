#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> jobid(n);
    for (int k = 0; k < n; k++)
    {
        cin >> jobid[k];
    }
    vector<int> deadline(n);
    for (int k = 0; k < n; k++)
    {
        cin >> deadline[k];
    }
    vector<int> profit(n);
    for (int k = 0; k < n; k++)
    {
        cin >> profit[k];
    }
    vector<pair<int, pair<int, int>>> v;
    for (int k = 0; k < n; k++)
    {
        int a = jobid[k];
        int b = deadline[k];
        int c = profit[k];
        v.push_back({c, {b, a}});
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans(n, -1);
    vector<int> fin;
    int pro = 0;
    int cnt = 0;
    for (int k = 0; k < n; k++)
    {
        int a = v[k].first;
        int b = v[k].second.first;
        int c = v[k].second.second;
        for (int j = b - 1; j >= 0; j--)
        {
            if (ans[j] == -1)
            {
                pro += a;
                ans[j] = c;
                cnt++;
                break;
            }
        }
    }
    cout << pro << endl;
    return 0;
}
