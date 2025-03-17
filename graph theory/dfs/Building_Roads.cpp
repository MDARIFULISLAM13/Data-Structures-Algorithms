/**
 *
 * Author : Md.Ariful Islam
 * Date : 09-12-2024
 * time : 23:34:10
 * Problem Name : Building_Roads
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
const int mx = 1e6 + 123;
vector<int>rood[mx];
vector<bool>ck(mx, 0);
void dfs(int x) {
    ck[x] = true;
    for (auto i : rood[x]) {
        if (ck[i] != true) {
            dfs(i);
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
        //input rood
        rood[x].push_back(y);
        rood[y].push_back(x);
    }
    int ans = 0;
    vector<int>new_rood;
    for (int i = 1;i <= n;i++) {
        if (ck[i] == 0) {
            //ck if not visited then dfs(i);
            ++ans;
            new_rood.push_back(i);
            dfs(i);
        }
    }
    if (ans == 1) {
        cout << 0 << endl;
    }
    else {
        cout << ans - 1 << endl;
        for (int i = 0;i < new_rood.size() - 1;i++) {
            cout << new_rood[i] << " " << new_rood[i + 1] << endl;
        }
    }

    return 0;
}