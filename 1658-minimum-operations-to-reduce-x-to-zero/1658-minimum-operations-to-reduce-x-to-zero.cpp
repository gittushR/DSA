// class Solution {
// public:
//     int helper(int left, int right, int num, vector<int> &nums,vector<vector<int>> &dp){
//         if(num==0)return 0;
//         if(left>right)return 1e5;
//         if(num<0)return 1e5;
//         if(dp[left][right]!=-1)return dp[left][right];
//         int leftRemove=1+helper(left+1,right,num-nums[left],nums,dp);
//         int rightRemove=1+helper(left,right-1,num-nums[right],nums,dp);
//         return dp[left][right]=min(leftRemove,rightRemove);
//     }
//     int minOperations(vector<int>& nums, int x) {
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
//         int ans=helper(0,nums.size()-1,x,nums,dp);
//         return ans>=1e5? -1: ans;
//     }
// };
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        for(auto &it : nums) tot+=it;
        int i=0,j=0, curr=0, sz=-1;
        while(i<=j and j<nums.size()){
            if(tot-curr>x){
                curr+=nums[j];
                j++;
            }
            else if(tot-curr<x){
                curr-=nums[i];
                i++;
            }
            else{
                sz = max(sz, j-i);
                curr+=nums[j++];
                curr-=nums[i++];
            }
        }
        while(i<=j and tot-curr<x){
            curr-=nums[i];
            i++;
        }
        if(tot-curr==x) sz = max(sz, j-i);
        if(sz==-1) return sz;
        return nums.size()-sz;
    }
};