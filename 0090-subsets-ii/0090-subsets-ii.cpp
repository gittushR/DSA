class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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