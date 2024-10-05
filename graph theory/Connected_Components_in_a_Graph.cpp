/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-10-2024
 * time : 15:28:29
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
vector<int>vc[mx];
vector<bool>ck(mx, 0);
void dfs(int i) {
    ck[i] = 1;
    for (auto u : vc[i]) {
        if (ck[u] == 0) {
            dfs(u);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int u, v;
        cin >> u >> v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1;i <= N;i++) {
        if (ck[i] == 0) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;

    return 0;
}