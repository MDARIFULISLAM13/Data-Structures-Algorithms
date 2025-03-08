/**
 *
 * Author : Md.Ariful Islam
 * Date : 09-03-2025
 * time : 00:12:54
 * Topic Name : binary Search
 **/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Array size n; find value key from this array
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    int l = 0, h = n;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] > key)
        {
            h = mid - 1;
        }
        else if (a[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            cout << "Value Found\n";
            return 0;
        }
    }
    cout << "NOt Found\n";

    return 0;
}