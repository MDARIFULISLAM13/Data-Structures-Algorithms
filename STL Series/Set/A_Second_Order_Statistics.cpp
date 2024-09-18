/**
 *
 * Author : Md.Ariful Islam
 * Date : 16-09-2024
 * time : 00:12:16
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

    set<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int v;
        cin >> v;
        s.insert(v);
    }
    if (s.size() < 2)
    {
        cout << "NO\n";
        return 0;
    }
    auto it = s.begin();
    it++;
    cout << *it;
    return 0;
}