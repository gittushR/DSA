//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int weight, int wt[], int val[],int index,vector<vector<int>>&dp){
        if(index==0){
            if(weight>=wt[0])return (weight/wt[0])*val[0];
            else return 0;
        }
        if(dp[index][weight]!=-1)return dp[index][weight];
        int notTake=f(weight,wt,val,index-1,dp);
        int take=-1e9;
        if(wt[index]<=weight)take=val[index]+f(weight-wt[index],wt,val,index,dp);
        return dp[index][weight]=max(take,notTake);
    }
    int knapSack(int n, int W, int val[], int wt[]) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return f(W,wt,val,n-1,dp);
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