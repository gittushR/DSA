//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int mod = 1e9+7;
    int f(int n,vector<int> &dp){
        if(n<0) return 0;
        if(n==0) return 1;
        
        if(dp[n]!=-1) return dp[n]%mod;
        
        dp[n] = (f(n-1,dp)%mod + f(n-2,dp)%mod)%mod;
        return dp[n]%mod;
    }
    int countWays(int n) {
        vector<int> dp(1e4,-1);
        return f(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends