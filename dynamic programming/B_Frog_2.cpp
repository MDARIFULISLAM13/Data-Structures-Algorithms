/**
 *
 * Author : Md.Ariful Islam
 * Date : 21-10-2024
 * time : 13:01:19
 * Problem Name : B_Frog_2
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
int dp[mx];
int v[mx];
int n, k;
int solve(int i) {
    if (i == n - 1) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    int ret = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i + j < n)
        {
            int cost = abs(v[i] - v[i + j]) + solve(i + j);
            ret = min(ret, cost);
        }
    }
    dp[i] = ret;
    return dp[i];


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0);


    return 0;
}