/**
 *
 * Author : Md.Ariful Islam
 * Date : 10-12-2024
 * time : 21:54:59
 * Problem Name : C_Mail_Stamps
 *
 **/
#ifdef __GNUC__
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif
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
#define mem(dp,i) memset(dp,i,sizeof(dp));

map<ll, vector<ll>>city;
map<ll, bool>chk;
map<ll, bool>ck;
ll start = 0;

int dfsc(int x) {
    if (start != 0) {
        return 0;
    }
    chk[x] = true;

    bool vis = false;
    for (auto i : city[x]) {
        if (chk[i] == 0 && start == 0) {
            vis = true;
            dfsc(i);
        }
    }
    if (vis == false) {
        start = x;
        return 0;
    }
}
int dfs(int x) {

    ck[x] = true;


    for (auto i : city[x]) {
        if (ck[i] == 0) {

            dfs(i);
        }
    }
    cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll u, v;
    for (int i = 1;i <= n;i++) {

        cin >> u >> v;

        city[u].push_back(v);
        city[v].push_back(u);
    }

    dfsc(u);


    dfs(start);
    return 0;
}

