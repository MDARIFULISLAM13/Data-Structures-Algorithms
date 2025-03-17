/**
 *
 * Author : Md.Ariful Islam
 * Date : 04-10-2024
 * time : 12:10:26
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
const int mx = 21;
char c[mx][mx];
bool ck[mx][mx];
int n, m, cnt = 0;
int dx[] = { 0,0,+1,-1 };
int dy[] = { +1,-1,0,0 };
void dfs(int x, int y) {
    ck[x][y] = 1;
    cnt++;
    for (int i = 0;i < 4;i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && c[x1][y1] == '.' && ck[x1][y1] == 0) {
            dfs(x1, y1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case " << i << ": ";

        cin >> m >> n;
        int x, y;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                cin >> c[i][j];
                if (c[i][j] == '@') {
                    x = i, y = j;
                }
            }


        }
        memset(ck, 0, sizeof(ck));
        cnt = 0;
        dfs(x, y);
        cout << cnt << endl;
    }

    return 0;
}