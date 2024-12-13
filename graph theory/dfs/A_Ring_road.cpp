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

const int mx = 110;

vector<pair<int, int>> road[mx];
bool ck[110] = { 0 };
int cost = 0;
int cost1 = 0;
int f = 0;
int s = 0;
bool f1 = 0;
void dfs(int x, int abba) {

    ck[x] = 1;
    for (auto& i : road[x]) {
        int c = i.second;
        int n = i.first;

        if (ck[n] == true && n != abba && n == f) {
            if (f1 == 0) {
                cost1 += c;
            }
            else {
                cost += c;
            }
            // cout << x << " " << i.first << " " << n << " " << i.second << endl;
            // cout << x << endl;

        }
        else if (ck[n] == 0) {
            // cout << x << " " << i.first << " " << n << " " << i.second << endl;
            if (f1 == 0) {
                cost1 += c;
            }
            else {
                cost += c;
            }
            dfs(n, x);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        f = a, s = b;


        road[a].push_back({ b, 0 });
        road[b].push_back({ a, c });
    }



    dfs(f, -1);
    f = s;
    f1 = 1;
    memset(ck, 0, sizeof(ck));
    dfs(f, -1);

    cout << min(cost, cost1);
    return 0;
}
