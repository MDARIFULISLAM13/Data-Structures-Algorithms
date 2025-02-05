/**
 *
 * Author : Md.Ariful Islam
 * Date : 14-12-2024
 * time : 18:19:47
 * Problem Name : A_Learning_Languages
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
vector<int>em[mx];
vector<int>lg[mx];
bool ck[mx] = { 0 };
bool vis[mx] = { 0 };
bool lvis[mx] = { 0 };
void ldfs(int x);
void dfs(int x);
void ldfs(int x) {
    lvis[x] = 1;
    for (auto i : lg[x]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}
void dfs(int x) {

    vis[x] = 1;

    for (auto i : em[x]) {
        if (lvis[i] == 0) {
            ldfs(i);
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        for (int j = 1;j <= x;j++) {
            int v;
            cin >> v;
            em[i].push_back(v);
            lg[v].push_back(i);
        }
    }
    int cnt = 0;
    bool fst = 0;
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) {

            if (em[i].size() == 0) {
                ++cnt;
            }
            else {

                if (fst == 0) {
                    fst = 1;
                }
                else {
                    ++cnt;
                }

                dfs(i);
            }

        }

    }

    cout << cnt;

    return 0;
}