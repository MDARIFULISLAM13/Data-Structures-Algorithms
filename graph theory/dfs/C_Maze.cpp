/**
 *
 * Author : Md.Ariful Islam
 * Date : 14-12-2024
 * time : 00:40:47
 * Problem Name : C_Maze
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
const int mx = 510;
char a[mx][mx];
bool ck[mx][mx];
int n, m, k;
int cnt = 0;
int cnx = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool isValid(int x, int y) {

    return (x >= 1 && x <= n && y >= 1 && y <= m && !ck[x][y] && a[x][y] == '.');
}

void dfs(int x, int y) {

    ck[x][y] = true;



    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];


        if (isValid(newX, newY)) {
            dfs(newX, newY);
        }
    }
    if (cnx < k) {
        ++cnx;

        a[x][y] = 'X';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    int x = -1, y = -1;
    bool fnd = false;;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];

            if (a[i][j] == '.') {

                ++cnt;
                if (fnd == false) {
                    fnd = true;
                    x = i;
                    y = j;
                }

            }
        }
    }
    if (fnd == true) {
        dfs(x, y);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cout << a[i][j];


        }
        cout << endl;
    }


    return 0;
}