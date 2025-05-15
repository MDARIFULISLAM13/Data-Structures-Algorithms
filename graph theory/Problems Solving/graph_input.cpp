/**
 *
 * Author : Md.Ariful Islam
 * Date : 03-10-2024
 * time : 10:50:40
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
const int mx = 1e5 + 123;
vector<pair<int, int>>adj[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    for (int i = 1;i <= n;i++) {
        cout << "Adjacent list of " << i << ": ";
        for (auto u : adj[i]) {
            cout << "NOde : " << u.first << " ANd cost " << u.second << " ";
        }
        cout << endl;
    }

    return 0;
}