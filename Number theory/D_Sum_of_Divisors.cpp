/**
 *
 * Author : Md.Ariful Islam
 * Date : 01-08-2024
 * time : 20:04:24
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

   int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        int v=i;
        while(v<=n){
            a[v]++;
            v+=i;


        }
    }
  ll ans=0;
  for(int i =1;i<=n;i++){
   ans+=(1ll*i*a[i]);
  }
  cout<<ans;



    return 0;
}