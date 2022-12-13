class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &arr,int target,int index,vector<int> &temp){
        if(target<0){
            return ;
        }
        if(index==arr.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(arr[index]);
        helper(ans,arr,target-arr[index],index,temp);
        temp.pop_back();
        helper(ans,arr,target,index+1,temp);              
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,candidates,target,0,temp);
        return ans;
    }
};