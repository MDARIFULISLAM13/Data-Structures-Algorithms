/**
 *
 * Author : Md.Ariful Islam
 * Date : 09-02-2025
 * time : 01:25:55
 * Problem Name : Labyrinth
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
const int mx = 1100;
char g[mx][mx];
bool vis[mx][mx];
pair<int, int>father[mx][mx];
int n, m;

bool valid(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m); // Fix boundary check
}
bool done = false;

void bfs(int X, int Y) {

    queue<pair<int, int>>q;
    q.push({ X, Y });
    vis[X][Y] = true;
    father[X][Y] = { -1,-1 };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        vector <pair<int, int>>v = { {x + 1,y},{x - 1,y},{x,y + 1},{x,y - 1} };
        for (auto [x1, y1] : v) {
            if (valid(x1, y1) && g[x1][y1] != '#' && !vis[x1][y1]) {

                vis[x1][y1] = true;
                q.push({ x1,y1 });
                father[x1][y1] = { x, y };
                if (g[x1][y1] == 'B') {
                    done = true;
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int x = 0, y = 0;
    int xb = 0, yb = 0;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                x = i, y = j;
            }
            if (g[i][j] == 'B') {
                xb = i, yb = j;
            }
        }
    }

    bfs(x, y);
    if (!done) {
        cout << "NO\n";
        return 0;
    }
    vector<char> ans;
    while (xb != -1 && yb != -1) {

        int f_x, f_y;
        tie(f_x, f_y) = father[xb][yb];
        if (f_x == -1 && f_y == -1)break;

        if (xb != f_x) {
            if (xb < f_x) {
                ans.push_back('U');
            }
            else {
                ans.push_back('D');
            }
        }
        else {
            if (yb < f_y) {
                ans.push_back('L');
            }
            else {
                ans.push_back('R');
            }
        }

        xb = f_x;
        yb = f_y;

    }

    reverse(ans.begin(), ans.end());
    cout << "YES\n" << ans.size() << endl;
    for (auto i : ans) {
        cout << i;
    }
}



