class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int leftSum = 0, rightSum = 0, n=nums.size();
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)
            rightSum += nums[i];
        for(int i=0; i<n; i++){
            ans[i] = (rightSum - (nums[i]*(n-i))) + ((nums[i]*i) - leftSum);
            rightSum -= nums[i];
            leftSum += nums[i];
        }
        return ans;
    }
};