/**
 *
 * Author : Md.Ariful Islam
 * Date : 13-12-2024
 * time : 22:49:57
 * Problem Name : J_Send_the_Fool_Further_easy
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
const int mx = 110;
vector<pair<int, int>>fnd[mx];
bool ck[mx] = { 0 };
int cost = 0;
void dfs(int x, int c) {
    ck[x] = 1;
    bool vis = false;

    for (auto& i : fnd[x]) {

        if (ck[i.first] == 0) {

            i.second += c;
            // cout << i.first << " " << i.second << endl;
            vis = true;
            dfs(i.first, i.second);
        }
    }
    if (vis == false) {
        cost = max(cost, c);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        fnd[a].push_back({ b,c });
        fnd[b].push_back({ a,c });
    }
    dfs(0, 0);
    cout << cost;

    return 0;
}