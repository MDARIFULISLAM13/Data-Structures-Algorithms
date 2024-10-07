/**
 *
 * Author : Md.Ariful Islam
 * Date : 07-10-2024
 * time : 09:25:21
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
const int mx = 1e6 + 123;
vector<int>v[mx];
vector<bool>ck(mx, 0);
int n, m;
void dfs(int i) {
    ck[i] = 1;
    for (auto u : v[i]) {
        if (ck[u] == 0) {
            dfs(u);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, U;
        cin >> u >> U;
        v[u].push_back(U);
        v[U].push_back(u);

    }
    int cnt = 0;
    vector<int>s;
    for (int i = 1;i <= n;i++) {
        if (ck[i] == 0) {
            dfs(i);
            cnt++;
            s.push_back(i);
        }

    }
    cout << cnt - 1 << endl;
    for (int i = 0;i < s.size() - 1;i++) {
        cout << s[i] << " " << s[i + 1] << endl;
    }

    return 0;
}