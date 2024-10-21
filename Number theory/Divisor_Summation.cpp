/**
 *
 * Author : Md.Ariful Islam
 * Date : 20-08-2024
 * time : 04:53:23
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
const long lm = 1e8 + 123;
bitset<lm> ip;
vector<int> p;
void arif(ll n)
{
    p.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        ip[i] = true;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (ip[i] == true)
        {
            for (int j = i + i; j <= n; j += i)
            {
                ip[j] = false;
            }
        }
    }
    ip[2] = true;
    for (int i = 3; i <= n; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
}
ll sod(ll n) {
    ll ans = 1;
    for (auto i : p) {
        if (1ll * i * i > n) {
            break;
        }
        if (n % i == 0) {
            ll sum = 1;
            ll a = 1;
            while (n % i == 0) {
                a *= i;
                sum += a;
                n /= i;
            }
            ans *= sum;
        }

    }
    if (n > 1) {
        ans *= (n + 1);
    }
    return ans;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(lm);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << sod(n) - n << endl;
    }
    return 0;
}