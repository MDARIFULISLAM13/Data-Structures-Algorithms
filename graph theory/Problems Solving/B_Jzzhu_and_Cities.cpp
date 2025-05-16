/**
 *
 * Author : Md.Ariful Islam
 * Date : 16-05-2025
 * time : 01:21:22
 * Problem Name : B_Jzzhu_and_Cities
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
const long long inf = 1e18;

vector<pair<int, int>> g[mx];

long long dis[mx];
long long dis1[mx];

void dijkstra(int source)
{

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();

        if (w > dis[v])
            continue;
        for (auto &baby : g[v])
        {
            int baby_v = baby.first;
            int baby_w = baby.second;

            if (w + baby_w < dis[baby_v])
            {
                dis[baby_v] = w + baby_w;
                pq.push({dis[baby_v], baby_v});
            }
        }
    }
}
int father[mx];
void dijkstra1(int source)
{

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dis1[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();

        if (w > dis1[v])
            continue;
        for (auto &baby : g[v])
        {
            int baby_v = baby.first;
            int baby_w = baby.second;

            if (w + baby_w < dis1[baby_v])
            {
                dis1[baby_v] = w + baby_w;
                pq.push({dis1[baby_v], baby_v});
                father[baby_v] = v;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
        
    }

    for (int i = 0; i <= n; i++)
    {

        dis[i] = inf;
    }
    dijkstra(1);

    ll cnt = 0;
    vector<pair<ll, ll>> vc;
    for (int i = 1; i <= t; i++)
    {
        int x, w;
        cin >> x >> w;
        vc.push_back({w, x});
        g[1].push_back({x, w});
        g[x].push_back({1, w});
    }

    for (int i = 0; i <= n; i++)
    {

        dis1[i] = inf;
    }
    dijkstra1(1);

    map<pair<int, int>, int> mp;

    for (int i = 0; i < t; i++)
    {
        int w = vc[i].first;
        int x = vc[i].second;
        if (mp[{w, x}] > 0)
        {
            ++cnt;
            continue;
        }
        mp[{w, x}]++;
        if (dis1[x] != w)
        {
            ++cnt;
        }
        else
        {
            if (dis[x] == dis1[x])
                ++cnt;
        }
    }
    cout << cnt << endl;

    return 0;
}