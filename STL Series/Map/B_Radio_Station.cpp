/**
 *
 * Author : Md.Ariful Islam
 * Date : 13-09-2024
 * time : 03:44:32
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

    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    while (n--)
    {
        string s, ss;
        cin >> s >> ss;
        mp[ss] = s;
    }
    while (m--)
    {
        string s, ss;
        cin >> s >> ss;
        cout << s << " " << ss << " #";
        ss.pop_back();
        cout << mp[ss] << endl;
    }

    return 0;
}