/**
 *
 * Author : Md.Ariful Islam
 * Date : 15-09-2024
 * time : 00:53:32
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

    vector<int> a(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < 5; i++)
    {
        int curr = a[i];
        int j = i - 1;
        while (a[j] > curr && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}