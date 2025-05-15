/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-10-2024
 * time : 08:41:10
 *
 **/
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
const int mx = 1e4 + 123;
vector<int>adj[mx];
int lev[mx];
void bfs(int s) {

    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int>q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (lev[u] == -1) {
                lev[u] = lev[v] + 1;
                q.push(u);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0;i <= mx;i++)adj[i].clear();

        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1);
        cout << lev[n] << endl;
    }

    return 0;
}