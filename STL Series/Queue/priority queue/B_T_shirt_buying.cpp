/**
 *
 * Author : Md.Ariful Islam
 * Date : 29-09-2024
 * time : 02:11:54
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
const int mx = 200000;
int a[mx];
int b[mx];
ll p[mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for (int i = 0;i < n;i++)cin >> p[i];
    for (int i = 0;i < n;i++)cin >> a[i];
    for (int i = 0;i < n;i++)cin >> b[i];
    priority_queue < int, vector<int>, greater<int>>price[4][4];
    for (int i = 0;i < n;i++) {
        price[a[i]][b[i]].push(p[i]);
    }
    ll m;
    cin >> m;
    while (m--) {
        int c;
        cin >> c;
        int ans = INT_MAX;
        int b = 0, f = 0;
        for (int i = 1;i <= 3;i++) {

            if (!price[i][c].empty() && price[i][c].top() < ans) {

                ans = price[i][c].top();
                b = i, f = c;

            }
            if (!price[c][i].empty() && price[c][i].top() < ans) {

                ans = price[c][i].top();
                b = c, f = i;

            }
        }

        if (ans == INT_MAX) {
            cout << "-1 ";
            continue;
        }
        else {
            cout << ans << " ";
            price[b][f].pop();
        }
    }


    return 0;
}