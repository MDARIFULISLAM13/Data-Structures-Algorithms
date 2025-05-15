/**
 *
 * Author : Md.Ariful Islam
 * Date : 18-03-2025
 * time : 04:30:41
 * Problem Name : E_Cyclic_Components
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
int n, m;
const int mx = 2 * 1e5 + 123;
vector<int> g[mx];
bool vis[mx];
int deg[mx];
vector<int> vc;
void dfs(int i)
{
    vis[i] = 1;
    vc.push_back(i);

    for (int x : g[i])
    {
        if (vis[x] == 0)
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        if (vis[i] == 0)
        {
            vc.clear();
            dfs(i);
            bool ok = true;
            for (int v : vc)
            {
                if (deg[v] != 2)
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}