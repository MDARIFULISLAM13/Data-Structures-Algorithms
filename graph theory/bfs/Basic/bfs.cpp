/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-02-2025
 * time : 02:39:23
 * Problem Name : basic_implement_bfs
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
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int level[N];

void bfs(int sourse)
{
    queue<int> q;
    q.push(sourse);
    vis[sourse] = 1;

    while (!q.empty())
    {
        int cur_v = q.front();
        // order of output
        cout << cur_v << " ";
        q.pop();
        for (int child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " :  " << level[i] << endl;
    }

    return 0;
}