/**
 *
 * Author : Md.Ariful Islam
 * Date : 29-09-2024
 * time : 03:14:10
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
void arif() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>>q;
    for (int i = 1;i <= n;i++) {
        int v;
        cin >> v;
        q.push(v);
    }
    ll ans = 0;
    while (q.size() > 1) {
        ll v = q.top();
        q.pop();
        v += q.top();
        ans += v;
        q.pop();
        q.push(v);

    }

    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        arif();
    }

    return 0;
}