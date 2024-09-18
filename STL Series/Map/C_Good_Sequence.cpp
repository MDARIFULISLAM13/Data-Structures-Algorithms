/**
 *
 * Author : Md.Ariful Islam
 * Date : 13-09-2024
 * time : 03:18:01
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
    int n;
    cin >> n;
    map<int, int> m;
    while (n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int ans = 0;
    for (auto &i : m)
    {
        if (i.first != i.second)
        {
            if (i.first > i.second)
            {
                ans += i.second;
            }
            else
            {
                ans += i.second - i.first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}