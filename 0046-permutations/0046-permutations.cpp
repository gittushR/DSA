class Solution {
public:
    void sets(vector<vector<int>> &ans, vector<int> &temp,vector<int> nums,int freq[]){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                sets(ans,temp,nums,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){freq[i]=0;}
        vector<int> temp;
        sets(ans,temp,nums,freq);
        return ans;
    }
};