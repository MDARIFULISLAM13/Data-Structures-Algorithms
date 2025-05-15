/**
 *
 * Author : Md.Ariful Islam
 * Date : 15-05-2025
 * time : 22:58:51
 **/

 #include <bits/stdc++.h>
 using namespace std;

 const int mx = 1e5 + 123;
 const long long inf = 1e18;

 vector<pair<int, int>> g[mx];

 bool vis[mx];
 long long dis[mx];
 int father[mx];
 int ans[mx];

 void dijkstra(int source)
 {
     set<pair<long long, int>> s;
     s.insert({0, source});
     dis[source] = 0;
     while (!s.empty())
     {
         auto x = *s.begin();
         int v = x.second;
         long long w = x.first;
         s.erase(s.begin());

         if (vis[v])
             continue;
         vis[v] = true;

         for (auto baby : g[v])
         {
             int baby_v = baby.first;
             int baby_w = baby.second;

             if (w + baby_w < dis[baby_v])
             {
                 dis[baby_v] = w + baby_w;
                 s.insert({dis[baby_v], baby_v});
                 father[baby_v] = v;
             }
         }
     }
 }

 int main()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     int n, m;
     cin >> n >> m;

     for (int i = 0; i <= n; i++)
     {
         vis[i] = false;
         dis[i] = inf;
         father[i] = -1;
     }

     for (int i = 1; i <= m; i++)
     {
         int x, y, w;
         cin >> x >> y >> w;
         g[x].push_back({y, w});
         g[y].push_back({x, w});
     }

     dijkstra(1);

     if (father[n] == -1)
     {
         cout << -1 << endl;
         return 0;
     }

     int len = 0, x = n;
     while (x != -1)
     {
         ans[len++] = x;
         x = father[x];
     }

     for (int i = len - 1; i >= 0; i--)
     {
         cout << ans[i] << " ";
     }

     return 0;
 }
