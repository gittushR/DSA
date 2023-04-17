class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> ans;
        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }
        for(auto it:ans){
            if(it.second%2==1){
                return false;
            }
        }
            return true;
        
    }
};