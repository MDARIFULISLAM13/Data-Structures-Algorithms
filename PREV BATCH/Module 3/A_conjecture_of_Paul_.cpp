
/**
 *
 * Author : Md.Ariful Islam
 * Date : 07-08-2024
 * time : 23:48:18
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
bitset<lm> pi;

void arif()
{
    pi[2] = true;

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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    arif();
    vector<int> p(lm);
    for (int i = 1; i <= 3200; i++)
    {
        for (int j = 1; j <= 60; j++)
        {
            ll v = pow(i, 2) + pow(j, 4);
            if (v <= lm && pi[v])

            {
                p[v] = 1;
            }
        }
    }
    for (int i = 1; i <= lm; i++)
    {
        p[i] = p[i] + p[i - 1];
    }
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << p[x] << endl;
    }

    return 0;
}