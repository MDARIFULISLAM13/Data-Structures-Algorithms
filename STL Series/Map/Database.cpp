/**
 *
 * Author : Md.Ariful Islam
 * Date : 13-09-2024
 * time : 21:05:46
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
void arif()
{
    int n, r;
    cin >> n >> r;
    map<int, map<int, int>> m;
    while (r--)
    {
        int i, c;
        cin >> i >> c;
        m[i][c]++;
    }
    for (const auto &out : m)
    {

        for (const auto &in : out.second)
        {
            if (in.second > 1)
            {
                cout << "impossible\n";
                return;
            }
        }
    }
    cout << "possible\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int n = 1;
    while (t--)
    {
        cout << "Scenario #" << n << ": ";
        n++;
        arif();
    }

    return 0;
}