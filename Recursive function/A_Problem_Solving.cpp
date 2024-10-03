/**
 *
 * Author : Md.Ariful Islam
 * Date : 30-09-2024
 * time : 22:06:41
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

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vec a(n);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int diff = a[0] - a[1];
        if (diff != 1) {
            cout << "Ambiguous\n";
            continue;;
        }
        cout << a[1] << endl;
    }

    return 0;
}