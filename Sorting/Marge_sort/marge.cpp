/**
 *
 * Author : Md.Ariful Islam
 * Date : 19-09-2024
 * time : 21:58:09
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
void marge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];

    }
    int i = 0, j = 0, k = n1 + n2;
    int v = l;
    for (int L = 0;L < k;L++) {
        if (a[i] <= b[j] || j == n2) {
            arr[v] = a[i];
            i++;
            v++;

        }
        else {
            arr[v] = b[j];
            v++;
            j++;
        }
    }

}
void margesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        margesort(arr, l, mid);
        margesort(arr, mid + 1, r);
        marge(arr, l, mid, r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[] = { 3,10,5,2,8,5,1,0,5 };
    margesort(arr, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}