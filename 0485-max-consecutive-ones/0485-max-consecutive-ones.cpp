class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]==0){
                ans=max(sum,ans);
                sum=0;
            }
        }
        return max(ans,sum);
    }
};