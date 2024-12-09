/**
 *
 * Author : Md.Ariful Islam
 * Date : 10-12-2024
 * time : 00:24:44
 * Problem Name : Subordinates
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
vector<int> m[mx];
vector<int>sub;
int dfs(int i) {

    int cnt = 0;
    for (auto x : m[i]) {
        cnt += 1 + dfs(x);
    }
    sub[i] = cnt;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        int boss;
        cin >> boss;
        m[boss].push_back(i);
    }
    sub.resize(n + 1, 0);
    dfs(1);
    for (int i = 1;i <= n;i++) {
        cout << sub[i] << " ";
    }
    return 0;
}