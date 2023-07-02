//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& nums) {
        // Code here
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastIndex=0;
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev_ind=0;prev_ind<ind;prev_ind++){
                if(nums[ind]%nums[prev_ind]==0 and 1+dp[prev_ind]>dp[ind]){
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
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends