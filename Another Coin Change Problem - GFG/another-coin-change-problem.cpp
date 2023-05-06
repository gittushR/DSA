//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool solve(vector<vector<int>>&dp,int n,int i,int k,int target,vector<int>&coins){
        if(target==0 && k==0){
            return true;
        }
        
        if(i==coins.size() || k<0){
            return false;
        }
        
        if(dp[k][target] != -1){
            return dp[k][target];
        }
        
        bool notTake=solve(dp,n,i+1,k,target,coins);
        bool take=false;
        if(target>=coins[i]){
            take=solve(dp,n,i,k-1,target-coins[i],coins);
        }
        return dp[k][target] = take||notTake;
        
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<int>> dp(K+1, vector<int> (target+1,-1));
        
        return solve(dp,N,0,K,target,coins);
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends