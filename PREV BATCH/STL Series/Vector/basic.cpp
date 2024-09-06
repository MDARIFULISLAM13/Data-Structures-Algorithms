/**
 *
 * Author : Md.Ariful Islam
 * Date : 01-09-2024
 * time : 10:28:24
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

    vector<int> a;
    for (auto i = 1; i < 11; i++)
    {
        a.push_back(i);
    }
    // a.clear();
    cout << a.empty() << endl;

    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    sort(a.begin(), a.end());
    a.pop_back();
    cout << *a.begin() << endl;
    for (int i : a)
    {
        cout << " " << i;
    }
    return 0;
}