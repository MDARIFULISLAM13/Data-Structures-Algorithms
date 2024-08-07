/**
 *
 * Author : Md.Ariful Islam
 * Date : 08-08-2024
 * time : 05:31:12
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
const int lim = 100000;
bitset<lim> pi;
void arif()
{
    pi[2] = true;
    for (int i = 3; i <= lim; i += 2)
    {
        pi[i] = true;
    }
    for (int i = 3; i <= sqrt(lim); i += 2)
    {
        if (pi[i] == true)
        {
            for (int j = i + i; j <= lim; j += i)
            {
                pi[j] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif();
    int n;
    cin >> n;
    if (n >= 3)
    {
        cout << "2\n";
    }
    else
    {
        cout << "1\n";
    }
    for (int i = 2; i <= n + 1; i++)
    {
        if (pi[i] == true)
        {
            cout << "1 ";
        }
        else
        {
            cout << "2 ";
        }
    }

    return 0;
}