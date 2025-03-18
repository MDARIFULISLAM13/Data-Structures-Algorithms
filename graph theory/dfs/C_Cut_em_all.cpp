/**
 *
 * Author : Md.Ariful Islam
 * Date : 18-03-2025
 * time : 21:05:58
 * Problem Name : C_Cut_em_all
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
const int mx = 1e5 + 123;
vector<int> g[mx];
int sub[mx];
int DFS(int baby, int baba)
{
    sub[baby] = 1;
    for (auto tar_baby : g[baby])
    {
        if (tar_baby != baba)
        {
            sub[baby] += DFS(tar_baby, baby);
        }
    }
    return sub[baby];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    if (t & 1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < t; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS(1, 0);
    int cnt = 0;
    for (auto i = 2; i <= t; i++)
    {
        if (sub[i] % 2 == 0)
            ++cnt;
    }

    cout << cnt << endl;

    return 0;
}