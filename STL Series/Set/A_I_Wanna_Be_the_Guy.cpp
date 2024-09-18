/**
 *
 * Author : Md.Ariful Islam
 * Date : 16-09-2024
 * time : 00:18:52
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
    set<int> s;
    int p;
    cin >> p;
    while (p--)
    {

        int v;
        cin >> v;
        if (v > 0)
            s.insert(v);
    }
    int q;
    cin >> q;
    while (q--)
    {

        int v;
        cin >> v;
        if (v > 0)
            s.insert(v);
    }
    auto it = s.begin();

    if (s.size() >= n && *it == 1)
    {
        cout << "I become the guy.\n";
        return 0;
    }
    cout << "Oh, my keyboard!\n";

    return 0;
}