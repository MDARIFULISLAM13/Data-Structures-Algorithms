/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-08-2024
 * time : 06:01:56
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
const int lm = 10000000;
bitset<lm> pi;
vector<int> p;
void arif()
{

    p.push_back(2);
    for (int i = 3; i <= lm; i += 2)
    {
        pi[i] = true;
    }
    for (int i = 3; i <= sqrt(lm); i += 2)
    {
        if (pi[i] == true)
        {
            for (int j = i + i; j <= lm; j += i)
            {
                pi[j] = false;
            }
        }
    }
    for (int i = 3; i <= lm; i += 2)
    {
        if (pi[i] == true)
        {
            p.push_back(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    int ans = 0, i = 0;
    if (n >= 2)
    {
        ans++;
    }

    while (p[i] < n)
    {
        i++;
        int v = p[i];
        int vv = v - 1;
        int v2 = sqrt(vv);
        int v4 = pow(vv, .25);
        if (pow(v2, 2) + 1 == v)
        {
            ans++;
        }
        else if (pow(v4, 4) + 1 == v)
        {
            ans++;
        }
        else if (pow(v2, 2) + pow(v4, 4) == v)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}