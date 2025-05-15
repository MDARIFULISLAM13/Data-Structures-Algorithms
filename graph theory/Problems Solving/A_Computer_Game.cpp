/**
 *
 * Author : Md.Ariful Islam
 * Date : 05-10-2024
 * time : 16:49:34
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
const int mx = 123;
char v[3][mx];
int ck[mx][mx];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int n;
bool out = false;
void dfs(int x, int y) {

    if (x == 2 && y == n) {

        out = true;

    }
    ck[x][y] = 1;
    for (int i = 0;i < 8;i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 1 && x1 <= 2 && y1 >= 1 && y1 <= n && v[x1][y1] == '0' && ck[x1][y1] == 0) {
            if (out) return; // Early exit if solution is found
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
    while (t--) {

        cin >> n;
        out = false;
        memset(ck, 0, sizeof(ck));
        for (int i = 0;i <= 3;i++) {
            for (int j = 0;j < mx;j++) {
                v[i][j] = '-';
            }
        }
        string a, b;
        cin >> a >> b;


        for (int i = 1;i <= 2;i++) {
            for (int j = 0;j < n;j++) {

                if (i == 1) {

                    v[i][j + 1] = a[j];



                }
                else {

                    v[i][j + 1] = b[j];

                }
            }
        }
        dfs(1, 1);
        if (out)yes;
        if (!out)no;
    }

    return 0;
}