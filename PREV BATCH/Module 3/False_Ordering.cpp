/**
 *
 * Author : Md.Ariful Islam
 * Date : 27-08-2024
 * time : 03:04:44
 *
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define endl "\n";
#define ft float
#define du double
#define ull unsigned long long
#define vec vector<ll>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> dv(1001, 0);
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j += i)
        {
            dv[j]++;
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i <= 1000; i++)
    {
        ans.push_back({dv[i], (i * -1)});
    }
    sort(ans.begin(), ans.end());
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        cout << "Case " << i << ": " << (ans[v].second * -1) << endl;
    }
    return 0;
}