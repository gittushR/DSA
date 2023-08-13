//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
  int helper(int n,vector<int> &dp){
      if(n<=2)return 1;
      if(dp[n]!=-1)return dp[n];
      return dp[n]=(helper(n-1,dp)%mod+helper(n-2,dp)%mod)%mod;
  }
    int nthFibonacci(int n){
        // code here
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends