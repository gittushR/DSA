//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(int ind,vector<int> heights,vector<int>&dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int climbOne=abs(heights[ind]-heights[ind-1])+fn(ind-1,heights,dp);
        int climbtwo=1e9;
        if(ind>1)climbtwo=abs(heights[ind]-heights[ind-2])+fn(ind-2,heights,dp);
        return dp[ind]=min(climbOne,climbtwo);
    }
    int minimumEnergy(vector<int>& heights, int n) {
        // Code here
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int ind=1;ind<n;ind++){
            int climbOne=abs(heights[ind]-heights[ind-1])+dp[ind-1];
            int climbtwo=1e9;
            if(ind>1)climbtwo=abs(heights[ind]-heights[ind-2])+dp[ind-2];
            dp[ind]=min(climbOne,climbtwo);
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends