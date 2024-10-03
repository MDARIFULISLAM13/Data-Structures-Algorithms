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

float arif(float d, float m) {
    if (d == 0) {
        return m;
    }
    return arif(d - 1, m) * 1.05;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    float d, m;
    cin >> d >> m;
    cout << fixed << setprecision(2) << arif(d, m);
    return 0;
}
