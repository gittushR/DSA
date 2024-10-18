class Solution {
public:
    int max=0;int res=0;
    void helper(vector<int> &nums, int start, int val){
        if(val==max)res++;
        for(int i=start;i<nums.size();i++){
            helper(nums,i+1,val | nums[i]);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto it: nums) max = max | it;
        helper(nums,0,0);
        return res;
    }
};