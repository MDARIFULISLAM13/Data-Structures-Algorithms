/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-02-2025
 * time : 23:08:07
 * Problem Name : Message_Route
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
vector<int>g[mx];
int lev[mx], father[mx];
void bfs(int source) {
    queue<int>q;
    q.push(source);
    lev[source] = 1;
    father[source] = -1;
    while (!q.empty()) {

        int curr = q.front();
        q.pop();

        for (auto i : g[curr]) {
            if (lev[i] == -1) {
                q.push(i);
                lev[i] = lev[curr] + 1;
                father[i] = curr;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(lev, -1, sizeof(lev));
    memset(father, -1, sizeof(father));
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
    if (lev[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << lev[n] << endl;

    vector<int>ans;
    ans.push_back(n);
    while (n != 1) {
        n = father[n];
        ans.push_back(n);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}