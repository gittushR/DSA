class Solution {
public:
    void sets(set<vector<int>> &st, vector<int>&temp,vector<int> nums, int freq[]){
        if(temp.size()==nums.size()){
            st.insert(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                sets(st,temp,nums,freq);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> st;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){freq[i]=0;}
        vector<int> temp;
        sets(st,temp,nums,freq);
        for(auto it:st){
            answer.push_back(it);
            st.erase(it);
        }
        return answer;
    }
};