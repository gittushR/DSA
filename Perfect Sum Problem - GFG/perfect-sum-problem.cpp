//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{

	public:
	int mod=1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(dp,arr,n,sum,0);
	}
	int helper(vector<vector<int>> &dp,int arr[],int n, int sum,int ind){
	    if(sum<0)return 0;
	    if(ind==n){
	        if(sum==0)return 1;
	        return 0;
	    }
	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    return dp[ind][sum]= (helper(dp,arr,n,sum-arr[ind],ind+1) % mod + helper(dp,arr,n,sum,ind+1)%mod)%mod;
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