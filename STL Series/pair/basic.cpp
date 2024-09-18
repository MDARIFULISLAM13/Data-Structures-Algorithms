/**
 *
 * Author : Md.Ariful Islam
 * Date : 06-09-2024
 * time : 16:44:02
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
    vector<pair<int, int>> v;
    v = {{2, 3}, {4, 5}, {1, 5}, {1, 6}, {6, 7}, {6, 8}};

    sort(v.rbegin(), v.rend());
    for (auto u : v)
        cout << u.first << " " << u.second << endl;
    cout << endl;

    return 0;
}