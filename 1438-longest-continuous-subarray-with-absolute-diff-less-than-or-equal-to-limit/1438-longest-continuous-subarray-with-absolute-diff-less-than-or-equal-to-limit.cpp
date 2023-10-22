class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        deque<int> minQueue;
        deque<int> maxQueue;
        int s=0,e=0;
        while(e<nums.size()){
            int x=nums[e];
            
            //add to end to maintain increasing order in minQueue as front element will give min
            while(!minQueue.empty() and nums[minQueue.back()]>=x)minQueue.pop_back();
            minQueue.push_back(e);
            
            //add to end of to maintain decreasing order in maxQueue as front element will give max
            while(!maxQueue.empty() and nums[maxQueue.back()]<=x)maxQueue.pop_back();
            maxQueue.push_back(e);
            
            int mini=nums[minQueue.front()];
            int maxi=nums[maxQueue.front()];
            if(maxi-mini>limit){
                s++;
                if(s>minQueue.front())minQueue.pop_front();
                if(s>maxQueue.front())maxQueue.pop_front();
            }else{
                ans=max(ans,e-s+1);
                e++;
            }
        }
        return ans;
    }
};