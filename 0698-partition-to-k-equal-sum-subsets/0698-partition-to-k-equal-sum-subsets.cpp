class Solution {
private:
    bool solve(vector<int> &nums,vector<int> &visited,int idx,int curSum,int target,int k){
        // Base case
        if(k == 1){
            return true;
        }

        if(curSum == target){
            return solve(nums,visited,0,0,target,k-1);
        }

        for(int i=idx;i<nums.size();i++){
            if(visited[i] || nums[i] + curSum > target){
                continue;
            }

            visited[i] = true;
            if(solve(nums,visited,i+1,curSum+nums[i],target,k)){
                return true;
            }
            visited[i] = false;
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        // Base case
        if(sum % k){
            return false;
        }

        int target = sum / k;
        vector<int> visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        return solve(nums,visited,0,0,target,k);
    }    
};