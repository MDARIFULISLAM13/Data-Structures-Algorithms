/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-08-2024
 * time : 03:20:42
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int lim = 1e8;
    bitset<mx> ip;
    vector<int> p;
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
    p.push_back(2);
    for (int i = 3; i <= lim; i += 2)
    {
        if (ip[i] == true)
        {
            p.push_back(i);
        }
    }
    for (int i = 0; i < p.size(); i += 100)
    {
        cout << p[i] << endl;
    }

    return 0;
}