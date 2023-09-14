//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

class Solution{
  public:
    int mod=1e9+7;
    int f(int arr[], int m, int N, vector<int>& dp){
        
        if(N == 0) return 1;
        if(N < 0) return 0;
        int ans = 0;
        if(dp[N] != -1) return dp[N];
        for(int i = 0; i <= m; i++){
           ans = (ans + f(arr, m, N-arr[i], dp))%mod; 
        }
        return dp[N] = ans%mod;
    }
   
   int countWays(int arr[], int m, int N){ 
       vector<int> dp(N+1, -1); //vector<int>(N+1, -1));
       return f(arr, m-1, N, dp);
   }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int m,n ;
	        cin>>m>>n;
	        int arr[m];
	        for(int i = 0;i<m;i++)
	            cin>>arr[i];
	        Solution ob;     
	        cout<<ob.countWays(arr,m,n)<<endl;
	    }
}
// } Driver Code Ends