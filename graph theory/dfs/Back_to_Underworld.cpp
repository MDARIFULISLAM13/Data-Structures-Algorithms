/**
 *
 * Author : Md.Ariful Islam
 * Date : 03-10-2024
 * time : 15:44:16
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
const int mx = 1e5 + 123;
vector<int> v[mx];
vector<bool> ck;  // Visited check
vector<bool> ick; // Track nodes that exist in the graph
int cnt1 = 0, cnt2 = 0;


void dfs(int i, int c) {
    int temp = 0;
    if (c == 1) {
        temp = 2;
        cnt1++;
    }
    else {
        cnt2++;
        temp = 1;
    }


    ck[i] = 1;


    for (auto u : v[i]) {
        if (ck[u] == 0) {
            dfs(u, temp);
        }
    }
}

void arif() {
    int n;
    cin >> n;
    int mxv = 0;


    while (n--) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        ick[x] = 1;
        ick[y] = 1;
        mxv = max(mxv, max(x, y));
    }

    int ans = 0;


    for (int i = 1; i <= mxv; i++) {
        if (ck[i] == 0 && ick[i] == 1) {
            cnt1 = 0, cnt2 = 0;
            dfs(i, 1);
            ans += max(cnt1, cnt2);
        }
    }

    cout << ans << endl;


    for (int i = 1; i <= mxv; i++) {
        v[i].clear();
        ck[i] = 0;
        ick[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;


    for (int i = 1; i <= t; i++) {

        ck.assign(mx, 0);
        ick.assign(mx, 0);
        v->assign(mx, 0);

        cout << "Case " << i << ": ";
        arif();
    }

    return 0;
}
