/**
 *
 * Author : Md.Ariful Islam
 * Date : 10-12-2024
 * time : 11:03:19
 * Problem Name : C_Kefa_and_Park
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
const int mx = 1e6;
vector<int>rood[mx];
vector<int>cat(mx, 0);
bool ck[mx] = { 0 };
int n, m;
int ans = 0;
void dfs(int x, int cnt) {
    ck[x] = 1;
    if (cat[x] == 0) {
        cnt = 0;
    }
    else {
        ++cnt;
    }
    if (cnt > m) {
        return;
    }
    bool vis = false;
    for (auto i : rood[x]) {
        if (ck[i] == 0) {
            vis = true;
            dfs(i, cnt);
        }

    }
    if (vis == false) {
        ++ans;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> cat[i];
    }
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        rood[x].push_back(y);
        rood[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;

    return 0;
}