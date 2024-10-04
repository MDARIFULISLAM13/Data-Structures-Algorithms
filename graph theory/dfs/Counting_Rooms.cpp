/**
 *
 * Author : Md.Ariful Islam
 * Date : 04-10-2024
 * time : 16:14:41
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
int const mx = 1001;
int n, m;
char c[mx][mx];
bool ck[mx][mx];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
    ck[x][y] = 1;
    c[x][y] = '#';

    for (int i = 0;i < 4;i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        // cout << x1 << " " << y1 << endl;
        // cout << c[x1][y1];
        if (ck[x1][y1] == 0 && c[x1][y1] == '.' && x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
            dfs(x1, y1);
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    memset(ck, 0, sizeof(ck));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (ck[i][j] == 0 && c[i][j] == '.') {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}