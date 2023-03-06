//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int noConseBits(int n) {
        int curr=0;
        for(int i=32;i>=0;i--){
            int t=(1<<i);
           // mask for current bit .
            if(t&n){
                curr++;
                if(curr==3){
                    n=(~t)&n;
                   // changing the third consecutive set bit to Zero(0).
                    curr=0;
                }
            }else{
                curr=0;
            }
        }
        return n;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends