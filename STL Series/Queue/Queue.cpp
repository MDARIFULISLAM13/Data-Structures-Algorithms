/**
 *
 * Author : Md.Ariful Islam
 * Date : 26-09-2024
 * time : 02:38:40
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int>a;
    a.push(2);
    a.push(4);
    cout << a.front();
    a.pop();
    cout << a.front();


    return 0;
}