class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
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