//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

long long mod=(1e9+7);
    long long f(int i, int j,vector<vector<long long>>&dp){
        if(i==0 and j==0)return 1;
        if(i<0 or j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long up=f(i,j-1,dp);
        long long left=f(i-1,j,dp);
        return dp[i][j]=(up+left)%mod;
    }
    long long numberOfPaths(int a, int b){
        // code here
        vector<vector<long long>>dp(a,vector<long long>(b,-1));
        return f(a-1,b-1,dp);
    }

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends