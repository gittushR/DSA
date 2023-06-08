//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j>=matrix.size() or j<0)return -1e9;
        if(i==0)return dp[0][j]=matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        
        int diagl=matrix[i][j]+f(i-1,j-1,matrix,dp);
        
        int diagr=matrix[i][j]+f(i-1,j+1,matrix,dp);
        
        return dp[i][j]=max(up,max(diagl,diagr));
    }
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int n=matrix.size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int a=0;a<n;a++){
            maxi=max(maxi,f(n-1,a,matrix,dp));
        }
        return maxi;
    }
};
/*
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j>=matrix.size() or j<0)return 1e9;
        if(i==0)return dp[0][j]=matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=matrix[i][j]+f(i-1,j,matrix,dp);
        
        int diagl=matrix[i][j]+f(i-1,j-1,matrix,dp);
        
        int diagr=matrix[i][j]+f(i-1,j+1,matrix,dp);
        
        return dp[i][j]=min(up,min(diagl,diagr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int maxi=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int a=0;a<n;a++){
            maxi=min(maxi,f(n-1,a,matrix,dp));
        }
        return maxi;
    }
};
*/


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends