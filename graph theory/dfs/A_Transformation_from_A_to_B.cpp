/**
 *
 * Author : Md.Ariful Islam
 * Date : 10-12-2024
 * time : 12:06:10
 * Problem Name : A_Transformation_from_A_to_B
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<int>ans;
    ans.push_back(m);
    while (m > n) {
        int last_digit = abs(m % 10);
        if (last_digit == 1) {

            m = m / 10;
            ans.push_back(m);
        }
        else if (m % 2 == 0) {
            m /= 2;
            ans.push_back(m);
        }
        else {
            break;
        }
    }
    if (m == n) {
        cout << "YES\n";
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}