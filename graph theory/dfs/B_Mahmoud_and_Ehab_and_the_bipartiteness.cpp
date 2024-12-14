/**
 *
 * Author : Md.Ariful Islam
 * Date : 14-12-2024
 * time : 16:47:22
 * Problem Name : B_Mahmoud_and_Ehab_and_the_bipartiteness
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
#define mem(dp,i) memset(dp,i,sizeof(dp));
const int mx = 1e5 + 123;
vector<ll>edgs[mx];
bool vis[mx] = { 0 };
int ck[mx] = { 0 };
ll cnt1 = 0, cnt0 = 0;
void dfs(int x, int u) {
    vis[x] = true;
    if (u == 1) {
        ck[x] = 0;
        cnt0++;
    }
    else {
        ck[x] = 1;
        cnt1++;
    }
    for (auto i : edgs[x]) {
        if (vis[i] == 0) {
            dfs(i, ck[x]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    int d = 0;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        d = u;
        edgs[u].push_back(v);
        edgs[v].push_back(u);
    }

    dfs(d, 0);
    cout << (cnt1 * cnt0) - (n - 1);
    return 0;
}