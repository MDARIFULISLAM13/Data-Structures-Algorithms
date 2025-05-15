/**
 *
 * Author : Md.Ariful Islam
 * Date : 06-10-2024
 * time : 12:36:42
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
map<string, vector<string>>adj;
map<string, string>abba;
map<string, int>lev;
void bfs(string s) {
    lev.clear();
    lev[s] = 1;
    queue<string>q;
    q.push(s);
    while (!q.empty()) {

        string u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (lev[v] == 0) {
                lev[v] = lev[u] + 1;
                abba[v] = u;
                q.push(v);


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
    for (int i = 1;i <= n;i++) {
        string u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    string s, t;
    cin >> s >> t;
    bfs(s);

    vector < pair<string, string>>path;

    while (t != s) {
        path.push_back({ abba[t],t });
        t = abba[t];
    }
    reverse(path.begin(), path.end());

    for (auto u : path) {
        cout << u.first << " " << u.second << endl;
    }

    return 0;
}