/**
 *
 * Author : Md.Ariful Islam
 * Date : 30-09-2024
 * time : 03:41:42
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <= sqrt(n);i++) {

        ans += (n / i) - i;
    }
    ans *= 2;
    ans += sqrt(n);
    // for (int i = 1;i <= n;i++) {
    //     ans += (n / i);
    // }
    cout << ans;

    return 0;
}