/**
 *
 * Author : Md.Ariful Islam
 * Date : 28-09-2024
 * time : 13:39:43
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
    deque<int>a;
    a.push_back(2);
    a.push_front(3);
    a.push_back(1);
    a.push_front(4);

    cout << a.front() << " " << a.back() << endl;

    return 0;
}