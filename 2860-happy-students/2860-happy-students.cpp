class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int numSelected=0;
        if(nums[0]>0)ans++;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            if( nums[i] <  i+1 && nums[i+1] > i+1)ans++;
        }
        if(nums.back()<nums.size())ans++;
        return ans;
    }
};