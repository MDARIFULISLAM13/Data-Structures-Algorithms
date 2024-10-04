/**
 *
 * Author : Md.Ariful Islam
 * Date : 03-10-2024
 * time : 13:14:04
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
vector<bool>ck(mx, 0);
int cnt = 0;
int mxcnt = 0;
void dfs(int i) {
    cnt++;
    ck[i] = 1;
    for (auto u : v[i]) {
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

    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans = 1;
    for (int i = 1;i <= n;i++) {
        if (ck[i] == 0) {
            cnt = 0;
            dfs(i);
            // cout << cnt << endl;
            ans *= pow(2, (cnt - 1));
        }
        else {
            cnt = 0;
        }

    }

    cout << ans << endl;

    return 0;
}