class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int first = 0;
        int minL = -1, maxL = -1;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                first = i + 1;
                minL = -1;
                maxL = -1;
            }
            if(nums[i] == minK) minL = i;
            if(nums[i] == maxK) maxL = i;
            if(minL != -1 && maxL != -1){
                ans += min(minL, maxL) - first + 1;
            }
        }
        return ans;

    }
};