class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0,shortest=1e9,n=nums.size(),sum=0;
        while(right<n){
            sum+=nums[right];
            if(sum>=target){
                while(sum>=target){
                    sum-=nums[left];
                    left++;
                }
                shortest=min(shortest,(right-left+1)+1);
            }
            right++;
        }
        return shortest==1e9? 0:shortest;
    }
};