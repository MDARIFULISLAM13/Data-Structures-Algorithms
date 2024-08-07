/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-08-2024
 * time : 05:48:21
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
    int i = 0;
    int ans = 0;
    while (true)
    {
        if (p[i] > n)
        {
            break;
        }
    }
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