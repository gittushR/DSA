class Solution {
public:
    bool isPossible(vector<int> nums, int maxDiff, int pairs){
        int count=0,i=1;
        while(i<nums.size()){
            if(nums[i]-nums[i-1]<=maxDiff){
                count++;
                i=i+2;
            }else{
                i++;
            }
        }
        return count>=pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0, high=nums.back()-nums.front();
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(nums,mid,p)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};