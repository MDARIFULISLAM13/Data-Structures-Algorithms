/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-08-2024
 * time : 04:23:08
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
const int mx = 1000000;
bitset<mx> ip;
vector<int> p;
void arif()
{
    int lim = 1000000;

    for (int i = 3; i <= lim; i += 2)
    {
        ip[i] = true;
    }
    for (int i = 3; i <= sqrt(lim); i += 2)
    {
        if (ip[i] == true)
        {
            for (int j = i + i; j <= lim; j += i)
            {
                ip[j] = false;
            }
        }
    }
    p.push_back(1);
    p.push_back(2);
    for (int i = 3; i <= mx; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif();
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        int h = n / 2, l = 0;
        for (int i = h; i >= 0; i--)
        {
            if (p[i] <= n)
            {
                h = i;
                break;
            }
        }
        cout << p[h];
        // while (true)
        // {
        //     if (p[h] + p[l] == n)
        //     {
        //         cout << n << " = " << l << " + " << h << endl;
        //         break;
        //     }
        //     else if ()
        // }
    }

    return 0;
}