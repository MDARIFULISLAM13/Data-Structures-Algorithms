/**
 *
 * Author : Md.Ariful Islam
 * Date : 19-09-2024
 * time : 04:15:54
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {

        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {

            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}