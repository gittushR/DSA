//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int mod=1e9+7;
	int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp){
        if(ind==0){
            if(arr[0]==0 and target==0)return 2;
            if(target==arr[0] or target==0)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int notTaken=findWaysUtil(ind-1,target,arr,dp);
        int taken=0;
        if(target>=arr[ind])taken=findWaysUtil(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=(taken%mod+notTaken%mod)%mod;
    }
	int perfectSum(int arr[], int n, int k){
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return findWaysUtil(n-1,k,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends