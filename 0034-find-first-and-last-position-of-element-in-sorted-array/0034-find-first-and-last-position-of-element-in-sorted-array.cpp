class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==0 || count(nums.begin(),nums.end(),target)==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        auto first=find(nums.begin(),nums.end(),target);
        ans.push_back(first-nums.begin());
        
        auto second=upper_bound(nums.begin(),nums.end(),target);
        ans.push_back(second-nums.begin()-1);
        
        return ans;
    }
};
