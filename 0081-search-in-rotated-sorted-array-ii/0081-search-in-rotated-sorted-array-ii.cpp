class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int beg=0,end=nums.size()-1,mid;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return true;
            if((nums[beg] == nums[mid]) && (nums[end] == nums[mid]))
            {
                beg++;
                end--;
            }
            else if(nums[beg]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[beg])
                    end=mid-1;
                else
                    beg=mid+1;
            }
            
            else
            {
                if(target>=nums[mid] && target<=nums[end])
                   beg=mid+1;
                else
                    end=mid-1;
            }
            
        }
        return false;
    } 
};