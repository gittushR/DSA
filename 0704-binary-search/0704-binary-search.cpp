class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size()){
            if(target==nums[i])
                return i;
            else
            i++;
        }
        return -1;
    }
};