//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod=1e9+7;
	    int f(int ind,vector<int>&dp){
	        if(ind ==0)return 1;
	        if(dp[ind]!=-1)return dp[ind];
	        int one=f(ind-1,dp);
	        int two=0;
	        if(ind>1)two=f(ind-2,dp);
	        return dp[ind]=(one+two)%mod;
	    }
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1,-1);
		    return f(n,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends