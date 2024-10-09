/**
 *
 * Author : Md.Ariful Islam
 * Date : 07-10-2024
 * Time : 19:52:52
 * Problem Name: Round Trip
 * Problem Link: https://cses.fi/problemset/task/1669
 *
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ft float
#define du double
#define ull unsigned long long
#define vec vector<ll>

vector<int> adj[100005];
bool vis[100005];
vector<int> cyc;

bool dfs(int s, int p) {
    vis[s] = true;
    for (auto i : adj[s]) {
        cyc.push_back(i);
        if (!vis[i]) {
            if (dfs(i, s)) return true;
        }
        else if (i != p) {
            return true;
        }
        cyc.pop_back();
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m; // Read number of nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Read edges
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cyc.push_back(i);
        if (!vis[i] && dfs(i, 0)) {
            vector<int> ans = { *cyc.rbegin() }; // Start with the last node in the cycle
            for (auto j = cyc.rbegin() + 1; j != cyc.rend(); j++) {
                ans.push_back(*j);
                if (*j == *cyc.rbegin()) break; // Stop when we complete the cycle
            }
            cout << ans.size() << endl; // Output the size of the cycle
            for (auto i : ans) cout << i << ' '; // Output the cycle
            return;
        }
        cyc.pop_back();
    }
    cout << "IMPOSSIBLE"; // No cycle found
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

#ifdef LOCAL
    clock_t tStart = clock();
    cerr << fixed << setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}
