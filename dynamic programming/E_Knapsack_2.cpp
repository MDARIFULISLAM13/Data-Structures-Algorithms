/**
 *
 * Author : Md.Ariful Islam
 * Date : 23-10-2024
 * time : 13:57:17
 * Problem Name : D_Knapsack_1
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
#define mem(dp,i) memset(dp,i,sizeof(dp));
const long long mx = 1e5 + 123;
long long dp[101][100 * 1000 + 1];
int u[123], v[123];
int n, s;
long long solve(int i, int cr) {
    if (i > n) {
        return 0;
    }
    if (dp[i][cr] != -1) {
        return dp[i][cr];
    }
    ll x = 0, y = 0;
    if (cr + u[i] <= s) {
        x = v[i] + solve(i + 1, u[i] + cr);
    }
    y = solve(i + 1, cr);
    dp[i][cr] = max(x, y);
    return dp[i][cr];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;

    for (int i = 1;i <= n;i++) {
        cin >> u[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0);

    return 0;
}



