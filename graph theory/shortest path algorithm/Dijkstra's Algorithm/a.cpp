/**
 *
 * Author : Md.Ariful Islam
 * Date : 15-05-2025
 * time : 22:58:51
 * Topic Name : find shortest path from source to n
 **/

#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 123;
const int inf = INT_MAX;
vector<pair<int, int>> g[mx];
vector<bool> vis(mx, 0);
vector<int> dis(mx, inf);
vector<int> father(mx, -1);

void dijkstra(int source)
{
    set<pair<int, int>> s;
    s.insert({0, source});
    dis[source] = 0;
    while (s.size() > 0)
    {
        auto x = *s.begin();
        int v = x.second;
        int w = x.first;
        s.erase(s.begin());

        if (vis[v])
            continue;
        vis[v] = 1;

        for (auto baby : g[v])
        {

            int baby_v = baby.first;
            int baby_w = baby.second;

            if (baby_w + w < dis[baby_v])
            {
                dis[baby_v] = baby_w + w;
                s.insert({dis[baby_v], baby_v});
                father[baby_v] = v;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
    }
    dijkstra(1);

    int x = n;
    while (x != -1)
    {
        cout << x << " ";
        x = father[x];
    }

    return 0;
}