/**
 *
 * Author : Md.Ariful Islam
 * Date : 18-03-2025
 * time : 02:29:49
 * Problem Name : A_A
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
int w, h;
char v[51][51];
int dp[51][51];
int dfs(int x, int y)
{
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }

    int ans = 1;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

    for (auto i : dir)
    {
        int X = x + i.first;
        int Y = y + i.second;
        if ((X >= 0 && X < h) && (Y >= 0 && Y < w) && v[X][Y] == v[x][y] + 1)
        {
            ans = max(ans,1 + dfs(X, Y));
        }
    }
    return dp[x][y] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 0;
    while (1)
    {
        cin >> h >> w;
        if (h == 0 && w == 0)
        {
            break;
        }
        cnt++;
        int ans = 0;
        memset(v, '0', sizeof(v));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> v[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {

                if (v[i][j] == 'A')
                {
                    ans = max(ans, dfs(i, j));
                }
            }
        }

        cout << "Case " << cnt << ": " << ans << endl;
    }

    return 0;
}