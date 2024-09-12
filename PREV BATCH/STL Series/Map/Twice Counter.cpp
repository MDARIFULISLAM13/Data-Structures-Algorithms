#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string list[n];

    // Read the list of words
    for (int i = 0; i < n; i++)
        cin >> list[i];
    map<string, int> m;
    for (auto s : list)
    {
        m[s]++;
    }
    int ans = 0;
    for (auto i : m)
    {
        if (i.second == 2)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
