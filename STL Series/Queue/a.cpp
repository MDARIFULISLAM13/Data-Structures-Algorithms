//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
public:

    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        queue<int>n;
        stack<int>nn;
        while (k != 0) {
            nn.push(q.front());
            q.pop();
            k--;
        }
        while (!nn.empty()) {
            n.push(nn.top());
            nn.pop();
        }
        while (!q.empty()) {
            n.push(q.front());
            q.pop();

        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends