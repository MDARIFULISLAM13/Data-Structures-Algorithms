/**
 *
 * Author : Md.Ariful Islam
 * Date : 22-10-2024
 * time : 18:07:57
 * Problem Name : C_Vacation
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

const int mx = 1e5 + 123;
int v[mx][4];
int dp[mx][4], n;
int solve(int i, int f1) {
    if (i > n) {
        return 0;
    }
    if (dp[i][f1] != -1) {
        return dp[i][f1];
    }
    int mx = 0;
    for (int j = 1;j <= 3;j++) {
        if (j != f1) {
            mx = max(mx, v[i][f1] + solve(i + 1, j));
        }
    }
    dp[i][f1] = mx;
    return dp[i][f1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> v[i][1] >> v[i][2] >> v[i][3];
    }
    mem(dp, -1);
    cout << solve(0, 0);

    return 0;
}