//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int n,int sum,vector<int> arr,vector<vector<int>> &dp){
        if(sum==0)return true;
        if(n==0)return (arr[0]==sum);
        if(dp[n][sum]!=-1)return dp[n][sum];
        bool notTake=f(n-1,sum,arr,dp);
        bool take=false;
        if(sum>=arr[n])take=f(n-1,sum-arr[n],arr,dp);
        return dp[n][sum]=(take or notTake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends