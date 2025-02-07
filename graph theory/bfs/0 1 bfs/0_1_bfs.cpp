/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-02-2025
 * time : 04:32:53
 * Problem Name : solve_using_dfs
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
const int inf = 1e9 + 10;
vector<pair<int, int>>g[mx];
vector<int>lev(mx, inf);

int n, m;
int bfs() {
    deque<int>q;
    q.push_back(1);
    lev[1] = 0;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();
        for (auto child : g[cur_v]) {
            int child_v = child.first;
            int wt = child.second;
            if (lev[cur_v] + wt < lev[child_v]) {
                lev[child_v] = lev[cur_v] + wt;
                if (wt == 1) {
                    q.push_back(child_v);
                }
                else {
                    q.push_front(child_v);
                }
            }
        }


    }
    return lev[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        if (x == y)continue;
        g[x].push_back({ y,0 });
        g[y].push_back({ x,1 });
    }

    cout << bfs();

    return 0;
}