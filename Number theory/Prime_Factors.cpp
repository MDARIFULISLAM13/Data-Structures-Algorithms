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
const int lm = 1e7 + 123;
bitset<lm> ip;
vector<int> p;
void arif(int n)
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
    for (int i = 3; i <= n; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
}
vector<int> primeFactors(ll n)
{
    vector<int> factors;

    for (auto i : p)
    {

        if (1LL * i * i > n)
            break;

        if (n % i == 0)
        {
            while (n % i == 0)
            {
                factors.push_back(i);
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        factors.push_back(n);
    }

    return factors;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif(1e7 + 123);
    ll v;
    while ((true))
    {
        cin >> v;
        if (v == 0)
        {
            return 0;
        }
        bool isNeg = false;
        if (v < 0)
        {
            isNeg = true;
            v *= -1;
        }
        vector<int> factors = primeFactors(v);
        if (isNeg)
        {
            v *= -1;
            factors.insert(factors.begin(), -1);
        }
        cout << v << " = " << factors[0];
        for (int i = 1; i < factors.size(); i++)
            cout << " x " << factors[i];
        cout << endl;
    }

    return 0;
}