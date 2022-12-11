class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
    int mini=0;
    int maxi=0;;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<nums[mini])mini=i;
        if(nums[i]>nums[maxi])maxi=i;
        }
        
        return answer(mini,maxi,nums.size());
    }
    int answer(int minindex, int maxindex,int n){
        int ans1=min( n-min(minindex,maxindex), max(minindex,maxindex)+1);

 int ans2= n - max(minindex,maxindex) + min(minindex,maxindex) + 1;

      return min(ans1,ans2);
    }
};