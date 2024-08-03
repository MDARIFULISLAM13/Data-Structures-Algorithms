/**
 *
 * Author : Md.Ariful Islam
 * Date : 02-08-2024
 * time : 23:18:05
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
const int mx = 1e8;
bitset<mx> isprime;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    isprime.set();
    int lim = 1e8;

    for (int i = 3; i <= lim; i++)
    {
        isprime[i] = 1;
    }
    for (int i = 3; i <= lim; i += 2)
    {
        for (int j = i + i; j <= lim; j += i)
        {
            isprime[j] = 0;
        }
    }
    cout << "2\n";
    for (int i = 3; i <= lim; i += 2)
    {
        if (isprime[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}
