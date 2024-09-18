/**
 *
 * Author : Md.Ariful Islam
 * Date : 01-09-2024
 * time : 12:06:26
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

    vector<int> a = {2, 2, 3, 4, 6, 8, 8, 2, 2};
    unique(a.begin(), a.end());
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << max_element(a.begin(), a.end()) - a.begin() << endl;
    cout << *max_element(a.begin(), a.end()) << endl;

    string s = "Ariful Islam Arif";
    string ss = "Arif";
    copy(s.begin() + 6, s.begin() + 12, back_inserter(ss));
    cout << ss << endl;

    return 0;
}