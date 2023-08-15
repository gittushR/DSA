//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int mod = 1e9+7;
    
    int ncr(int n, int r){
        mod = 1e9 + 7;
        vector<long> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i<=n; i++){
            dp[i] = (i*dp[i-1])%mod;
        }
        if(r>n){
            return 0;
        }
        long up = dp[n], down = (dp[r]*dp[n-r])%mod;
        long ans = (up*power(down, mod-2, mod))%mod;
        int got = ans;
        return got;
    }
    long power(long x, long y, long mod){ //correct n^p = n^p/2 +
        if(y==0)    return 1;
        long p = power(x,y/2,mod)%mod;
        p = (p*p)%mod;
        return (y%2==0)?p:(x*p)%mod;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        Solution ob;
        cout << ob.ncr(n, r) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends