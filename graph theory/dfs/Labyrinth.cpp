/**
 *
 * Author : Md.Ariful Islam
 * Date : 04-10-2024
 * time : 16:59:42
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
int n, m;
const int mx = 1000;
char c[mx][mx];
bool ck[mx][mx];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
    ck[x][y] = 1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(ck, 0, sizeof(ck));
    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> c[i][j];
            if (c[i][j] == 'A') {
                x = i, y = j;
            }
        }
    }
    dfs(x, y);


    return 0;
}