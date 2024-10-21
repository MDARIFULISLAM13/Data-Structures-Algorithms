/**
 *
 * Author : Md.Ariful Islam
 * Date : 21-10-2024
 * time : 12:54:15
 * Problem Name : A_Frog_1
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
int n;
int solve(int i) {
    if (i == n) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    ll x = INT_MAX; ll y = INT_MAX;
    if (i + 1 <= n) {
        x = abs(v[i] - v[i + 1]) + solve(i + 1);
    }
    if (i + 2 <= n) {
        y = abs(v[i] - v[i + 2]) + solve(i + 2);
    }
    dp[i] = min(x, y);
    return dp[i];

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1);


    return 0;
}