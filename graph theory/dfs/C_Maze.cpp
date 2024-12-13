/**
 *
 * Author : Md.Ariful Islam
 * Date : 14-12-2024
 * time : 00:40:47
 * Problem Name : C_Maze
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
const int mx = 510;
int a[mx][mx];
bool ck[mx][mx];
int n, m, k;
int cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }

    return 0;
}