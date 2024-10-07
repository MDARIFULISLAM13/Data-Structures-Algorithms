/**
 *
 * Author : Md.Ariful Islam
 * Date : 07-10-2024
 * time : 09:43:30
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
const int mx = 1e5 + 123;
vector<int>v[mx];
int n, m;
int lev[mx];
bool ck = false;
map<int, int>abba;
void bfs(int s) {
    memset(lev, -1, sizeof(lev));
    lev[s] = 1;

    queue<int>q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        if (u == n) {
            ck = true;
            return;
        }
        q.pop();
        for (auto i : v[u]) {
            if (lev[i] == -1) {
                lev[i] = lev[u] + 1;
                abba[i] = u;
                q.push(i);

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int U, u;
        cin >> u >> U;
        v[u].push_back(U);
        v[U].push_back(u);
    }
    bfs(1);
    if (ck == true) {
        vector<int>ans;
        ans.push_back(n);
        cout << lev[n] << endl;
        while (n != 1) {
            ans.push_back(abba[n]);
            n = abba[n];
        }
        reverse(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }

    }
    else {
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}