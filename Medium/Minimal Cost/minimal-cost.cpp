//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(int ind, int k, vector<int> height,vector<int> &dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int minSteps=1e9;
        
        for(int i=1;i<=k;i++){
            int jump=1e9;
            if(ind-i>=0)jump=abs(height[ind]-height[ind-i])+fn(ind-i,k,height,dp);
            minSteps=min(minSteps, jump);
        }
        return dp[ind]=minSteps; 
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,0);
        for(int ind=1;ind<n;ind++){
            int minSteps=1e9;
            for(int i=1;i<=k;i++){
                int jump=1e9;
                if(ind-i>=0)jump=abs(height[ind]-height[ind-i])+dp[ind-i];
                minSteps=min(minSteps, jump);
            }
            dp[ind]=minSteps;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends