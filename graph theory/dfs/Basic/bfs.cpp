/**
 *
 * Author : Md.Ariful Islam
 * Date : 18-03-2025
 * time : 20:37:50
 * Problem Name : bfs
 *
 **/
#ifdef __GNUC__
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif
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
#define mem(dp, i) memset(dp, i, sizeof(dp));
const int mx = 100;
vector<int> g[mx];
bool vis[mx] = {0};
void dfs(int i)
{
    vis[i] = true;
    for (int x : g[i])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}