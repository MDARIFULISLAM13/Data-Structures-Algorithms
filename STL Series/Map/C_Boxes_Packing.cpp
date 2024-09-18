/**
 *
 * Author : Md.Ariful Islam
 * Date : 13-09-2024
 * time : 04:04:32
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

    int t;
    cin >> t;
    map<int, int> m;
    while (t--)
    {
        ll x;
        cin >> x;
        m[x]++;
    }
    bool first = false;
    int total_box = 0, faka_box = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it)
    {

        if (first == false)
        {
            first = true;
            total_box = it->second;
            faka_box = total_box;
            continue;
        }
        if (faka_box >= it->second)
        {
            continue;
        }
        else
        {
            it->second -= faka_box;
            total_box += it->second;
            faka_box += it->second;
        }
    }
    cout << total_box;
    return 0;
}