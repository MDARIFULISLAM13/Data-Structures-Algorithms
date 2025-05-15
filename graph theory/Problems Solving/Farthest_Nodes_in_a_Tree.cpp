#include <bits/stdc++.h>
using namespace std;

const int mx = 30005;
vector<pair<int, int>> adj[mx];
int dist[mx];

pair<int, int> bfs(int start, int n)
{
    fill(dist, dist + n, -1); // Reset distances
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int farthest_node = start, max_dist = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto [v, w] : adj[u])
        {
            if (dist[v] == -1)
            { // Not visited
                dist[v] = dist[u] + w;
                q.push(v);

                if (dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    farthest_node = v;
                }
            }
        }
    }
    return {farthest_node, max_dist};
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        adj[i].clear(); // Clear graph

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // First BFS from node 0
    int farthest_node = bfs(0, n).first;
    // Second BFS from farthest_node to get max distance
    int max_distance = bfs(farthest_node, n).second;

    static int case_no = 1;
    cout << "Case " << case_no++ << ": " << max_distance << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
