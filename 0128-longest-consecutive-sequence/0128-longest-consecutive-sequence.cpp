
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        sort(nums.begin(), nums.end());
        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                }
                else{
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         if(n<=1)return n;
//         int maxi=*max_element(nums.begin(),nums.end());
//         int mini=*min_element(nums.begin(),nums.end());
//         unordered_map<int,int> hash;
//         for(int i=0;i<maxi+1;i++)hash[i]=0;
//         for(int i=0;i<n;i++){
//             hash[nums[i]]=1;
//         }
//         int ans=1,curr=0;
//         for(int i=mini;i<=maxi;i++){
//             if(hash.find(i)!=hash.end() and hash[i]==1){
//                 curr++;
//             }else{
//                 ans=max(ans,curr);
//                 curr=0;
//             }
//         }
//         return max(ans,curr);
//     }
// };