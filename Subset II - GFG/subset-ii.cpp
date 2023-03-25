//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int> ds;
        helper(0,ans,ds,nums);
        return ans;
    }
    void helper(int index, vector<vector<int>>&ans,vector<int> &ds, vector<int> nums){
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            helper(i+1,ans,ds,nums);
            ds.pop_back();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends