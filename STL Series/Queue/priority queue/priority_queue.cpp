/**
 *
 * Author : Md.Ariful Islam
 * Date : 28-09-2024
 * time : 13:44:26
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
    //for decreasing order
    priority_queue<int>a;
    a.push(1);
    a.push(2);
    a.push(3);

    while (!a.empty()) {
        cout << a.top() << endl;
        a.pop();
    }

    //for increasing order
    priority_queue<int, vector<int>, greater<int>>a;
    a.push(1);
    a.push(2);
    a.push(3);

    while (!a.empty()) {
        cout << a.top() << endl;
        a.pop();
    }

    return 0;
}