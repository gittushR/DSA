class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp; mp[0]=-1;
        int sum = 0,longest_subarray = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? - 1 : 1;    
            if(mp.find(sum) != mp.end()){
                int length=i-mp[sum];
                longest_subarray=max(longest_subarray,length);
            }
            else{
                mp[sum] = i;
            }
        }
        return longest_subarray;
    }
};