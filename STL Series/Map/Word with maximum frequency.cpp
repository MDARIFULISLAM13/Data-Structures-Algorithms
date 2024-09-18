/**
 *
 * Author : Md.Ariful Islam
 * Date : 12-09-2024
 * time : 15:35:12
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
    string s = "rjs kot w lmy nh fn zo cfg bl m q ms pnt tko iym uo nmx jl vn i sin";
    vector<string> v;
    stringstream ss(s);
    vector<pair<string, int>> a;
    map<string, int> m;
    for (string w; ss >> w;)
    {
        m[w]++;
        v.push_back(w);
    }

    string ans = "";
    int frq = 0;
    int mxf = 0;
    vector<string> str;
    for (auto &i : m)
    {

        if (i.second > frq)
        {

            frq = i.second;
            ans = i.first;
            mxf = 1;
            str.clear();
            str.push_back(i.first);
        }
        else if (i.second == frq)
        {
            mxf++;
            str.push_back(i.first);
        }
    }
    if (mxf == 1)
    {
        ans = ans + " " + to_string(frq);
        cout << ans;
    }
    else
    {
        for (string i : v)
        {
            auto it = find(str.begin(), str.end(), i);
            if (it != str.end())
            {
                cout << *it << " " << frq;
                return 0;
            }
        }
    }

    return 0;
}