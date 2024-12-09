/**
 *
 * Author : Md.Ariful Islam
 * Date : 23-10-2024
 * time : 15:17:41
 * Problem Name : The_Knapsack_Problem
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
const int mx = 2000 + 123;
int dp[mx][mx];
int u[mx], v[mx];
int n, s;
long long solve(int i, int cr) {
    if (i > n) {
        return 0;
    }
    if (dp[i][cr] != -1) {
        return dp[i][cr];
    }
    long long x = 0, y = 0;
    if (u[i] + cr <= s) {
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
    cin >> s >> n;
    for (int i = 1;i <= n;i++) {
        cin >> u[i] >> v[i];
    }
    mem(dp, -1);
    cout << solve(1, 0);


    return 0;
}