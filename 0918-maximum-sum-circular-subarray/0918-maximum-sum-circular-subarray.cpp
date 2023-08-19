class Solution {
public:
    int kadanes(vector<int> nums){
        int sum=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int linearSum=kadanes(nums);
        if(linearSum<0)return linearSum;
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
            nums[i]=-nums[i];
        }
        int circularSum=totalSum+kadanes(nums);
        return max(linearSum,circularSum);
    }
};