/**
 *
 * Author : Md.Ariful Islam
 * Date : 30-09-2024
 * time : 04:06:17
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
int dp[1010];
int arif(int n) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = arif(n - 1) + arif(n - 2);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0;i < 1010;i++) {

        dp[i] = -1;
    }
    int n;
    cin >> n;
    cout << arif(n);

    return 0;
}