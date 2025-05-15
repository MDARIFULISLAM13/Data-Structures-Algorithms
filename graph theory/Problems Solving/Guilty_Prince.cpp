
/**
 *
 * Author : Md.Ariful Islam
 * Date : 18-03-2025
 * time : 22:27:28
 * Problem Name : Guilty_Prince
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
#define mem(dp, i) memset(dp, i, sizeof(dp));
int n, m;
char g[21][21];
bool ck[21][21];
int cnt;
void dfs(int x, int y)
{
    ++cnt;
    ck[x][y] = 1;

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto i : dir)
    {
        int X = x + i.first;
        int Y = y + i.second;

        if ((X >= 0 && X < m) && (Y >= 0 && Y < n))
        {
            if (g[X][Y] == '.' && ck[X][Y] == 0)
            {
                dfs(X, Y);
            }
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
    for (int i = 1; i <= t; i++)
    {
        n = m = cnt = 0;
        memset(g, '_', sizeof(g));
        memset(ck, 0, sizeof(ck));
        cin >> n >> m;
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == '@')
                {
                    x = i, y = j;
                }
            }
        }
        dfs(x, y);
        cout << "Case " << i << ": " << cnt << endl;
    }

    return 0;
}
