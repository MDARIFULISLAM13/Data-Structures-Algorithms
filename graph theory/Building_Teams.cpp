/**
 *
 * Author : Md.Ariful Islam
 * Date : 07-10-2024
 * time : 13:11:40
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
int n, m;
const int mx = 1e5 + 123;
vector<int>f[mx];
int t[mx];
bool ck = true;
void dfs(int x) {

    for (auto u : f[x]) {
        if (t[u] == 0) {
            if (t[x] == 1) {
                t[u] = 2;
            }
            else {
                t[u] = 1;
            }
            dfs(u);
        }
        else if (t[u] == t[x]) {
            ck = false;
            return;
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
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    memset(t, 0, sizeof(t));
    for (int i = 1;i <= n;i++) {
        if (ck == false) {
            break;
        }
        if (t[i] == 0) {
            t[i] = 1;
            dfs(i);


        }
    }
    if (ck == true) {
        for (int i = 1;i <= n;i++) {
            cout << t[i] << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}


