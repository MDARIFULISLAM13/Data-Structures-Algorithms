/**
 *
 * Author : Md.Ariful Islam
 * Date : 19-03-2025
 * time : 03:05:13
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
#define mem(dp, i) memset(dp, i, sizeof(dp));
int n, m, k;
char c[501][501];
bool vis[501][501];
int cnt = 0;
int ncnt = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isValid(int x, int y)
{

    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && c[x][y] == '.');
}
void bfs(int x, int y)
{
    vis[x][y] = 1;
    ++ncnt;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newX = curr.first + dx[i];
            int newY = curr.second + dy[i];

            if (isValid(newX, newY))
            {
                vis[newX][newY] = 1;
                q.push({newX, newY});
                if ((ncnt + k) >= cnt)
                {
                    c[newX][newY] = 'X';
                }
                ++ncnt;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    int x = 0, y = 0;
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '.')
            {
                ++cnt;
                if (f == 0)
                {

                    x = i, y = j;
                    f = 1;
                }
            }
        }
    }
    bfs(x, y);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[i][j];
        }
        cout << endl;
    }

    return 0;
}