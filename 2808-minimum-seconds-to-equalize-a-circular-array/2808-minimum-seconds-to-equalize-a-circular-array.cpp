class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
//         int n=nums.size();map<int,int> mp;
//         for(int i=0;i<n;i++){
//             mp[nums[i]]++;
//         }
//         cout<<mp.size()<<"****";
//         if(mp.size()==1)return 0;
//         if(mp.size()==n)return n/2;
//         if(n==3)return 1;
//         int maxNum=0,maxNumOcc=INT_MIN;
//         for(auto it:mp){
//             if(it.second>maxNumOcc){
//                 maxNum=it.first;
//                 maxNumOcc=it.second;
//             }
//         }
//         cout<<maxNum<<"***";
//         int prevIndex=-1,minDiff=1e9;
//         for(int i=0;i<n;i++){
//             if(nums[i]==maxNum){
//                 if(prevIndex==-1){
//                     prevIndex=i;
//                 }else{
//                     minDiff=min(minDiff,i-prevIndex);
//                 }
//             }
//         }
//         cout<<minDiff;
//         if(minDiff==1)return n%2==0? (n-2)/2 : (n-1)/2;
//         return (minDiff)/2;
        vector<int> v;
        for(auto i:nums){
            v.push_back(i);
        }
         for(auto i:nums){
            v.push_back(i);
        }
        int ans = INT_MAX, n = nums.size();
        unordered_map<int, int> lastSeen, maxDiff;
        for(int i = 0; i < v.size(); ++i){
            if(lastSeen.find(v[i]) != lastSeen.end()){
                maxDiff[v[i]] = max(maxDiff[v[i]], i - lastSeen[v[i]] - 1);
            }
            lastSeen[v[i]] = i;
        }
        for(auto [k, val]: maxDiff) ans = min(ans, val);  
        return (ans + 1)/2; 
    }
};