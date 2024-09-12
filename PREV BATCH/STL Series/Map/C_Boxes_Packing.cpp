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
    vector<ll> box;
    while (t--)
    {
        ll x;
        cin >> x;
        box.push_back(x);
    }
    sort(box.begin(), box.end());

    return 0;
}