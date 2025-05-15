/**
 *
 * Author : Md.Ariful Islam
 * Date : 15-05-2025
 * time : 20:13:30
 * Topic Name : dijkstra
 **/

#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 123;
const int inf = INT_MAX;
vector<pair<int, int>> g[mx];
vector<bool> vis(mx, false);
vector<int> dist(mx, inf);

void dijkstra(int sourse)
{
    set<pair<int, int>> st;
    st.insert({0, sourse});
    dist[sourse] = 0;
    while (st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin());
        int v = node.second;
        int dis = node.first;
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int child_dist = child.second;

            if (dist[v] + child_dist < dist[child_v])
            {
                dist[child_v] = dist[v] + child_dist;
                st.insert({dist[child_v], child_v});
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
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    dijkstra(1);
   

    return 0;
}