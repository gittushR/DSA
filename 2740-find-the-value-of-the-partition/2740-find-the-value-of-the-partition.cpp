class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            int part=nums[i+1]-nums[i];
            mini=min(mini,part);
        }
        return mini;
    }
};