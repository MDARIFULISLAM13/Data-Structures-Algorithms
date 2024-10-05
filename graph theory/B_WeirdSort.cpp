/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-10-2024
 * time : 18:38:40
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
    ll n, m;
    cin >> n >> m;
    vec a(n + 1), b(n + 1, 0);
    a[0] = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];

    }
    for (int i = 1;i <= m;i++) {
        int v;
        cin >> v;
        b[v] = 1;
    }
    bool ck = true;
    while (ck) {
        ck = false;
        for (int i = 1;i <= n;i++) {
            if (a[i] > a[i + 1] && b[i] == 1) {
                swap(a[i], a[i + 1]);
                ck = true;
            }
        }
    }


    if (is_sorted(a.begin(), a.end())) {
        yes;
    }
    else {
        no;
    }

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