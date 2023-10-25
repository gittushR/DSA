//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int weight, int val[], int wt[], int ind, vector<vector<int>> &dp){
        if(ind==0){
            if(weight>=wt[0]) return (weight/wt[0])*val[0];
            else return 0;
        }
        if(dp[ind][weight]!=-1)return dp[ind][weight];
        int notTaken = helper(weight,val,wt,ind-1,dp);
        int taken = -1e9;
        if(weight>=wt[ind])taken= val[ind]+helper(weight-wt[ind],val,wt,ind,dp);
        return dp[ind][weight]=max(notTaken,taken);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return helper(W,val,wt,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends