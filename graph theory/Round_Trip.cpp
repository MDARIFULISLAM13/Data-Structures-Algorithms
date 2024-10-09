/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-10-2024
 * time : 14:16:07
 * Problem Name : Round_Trip
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
vector<int>rd[mx];
bool vis[mx];
vector<int>abba;
bool found = false;

bool dfs(int s, int f) {
    vis[s] = true;

    for (auto i : rd[s]) {
        abba.push_back(i);
        if (!vis[i]) {
            if (dfs(i, s)) return true;

        }
        else if (i != f) return true;
        abba.pop_back();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        rd[u].push_back(v);
        rd[v].push_back(u);
    }
    for (int i = 1;i <= n;i++) {
        if (found == true) {
            break;
        }
        abba.push_back(i);
        if (!vis[i] && dfs(i, 0)) {
            found = true;
            break;
        }
        abba.pop_back();

    }
    if (!found) {
        cout << "IMPOSSIBLE";
    }
    else {

        int x = abba.back();
        vector<int>ans;
        int sz = 0;
        bool out = false;
        for (auto i : abba) {
            if (i == x) {
                out = true;
            }
            if (out == true) {
                ans.push_back(i);
                sz++;

            }
        }
        cout << sz << endl;
        for (auto i : ans) {
            cout << i << " ";
        }


    }



    return 0;
}