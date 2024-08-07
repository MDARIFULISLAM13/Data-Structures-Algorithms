
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
const int lm = 1000000;
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
void ans(int n)
{
    int h = p.size();
    int l = 0;
    int pos = 0;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (p[m] > n)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
            pos = m;
        }
    }
    l = 0;
    while (l <= pos)
    {
        if (p[l] + p[pos] == n)
        {
            cout << n << " = " << p[l] << " + " << p[pos] << endl;
            return;
            break;
        }
        else if (p[l] + p[pos] > n)
        {
            pos--;
        }
        else
        {
            l++;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
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
            break;
        }
        ans(n);
    }
    return 0;
}