//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastIndex=0;
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[prev_ind]<nums[ind] and 1+dp[prev_ind]>dp[ind]){
                    dp[ind]=1+dp[prev_ind];
                    hash[ind]=prev_ind;
                }
            }
            if(dp[ind]>maxi){
                maxi=dp[ind];
                lastIndex=ind;
            }
        }
        vector<int> lis;
        while(lastIndex!=hash[lastIndex]){
            lis.push_back(nums[lastIndex]);
            lastIndex=hash[lastIndex];
        }
        lis.push_back(nums[lastIndex]);
        reverse(lis.begin(),lis.end());
        return lis;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends