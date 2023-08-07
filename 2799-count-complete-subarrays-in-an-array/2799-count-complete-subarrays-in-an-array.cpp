class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), k = unordered_set<int>(nums.begin(), nums.end()).size();
        int res = 0, i = 0;
        unordered_map<int, int> count;
        for (int j = 0; j < n; ++j) {
            count[nums[j]]++;
            if(count[nums[j]] == 1) k--;
            while(k == 0) {
                count[nums[i]]--;
                if(count[nums[i++]] == 0) k += 1;
            }
            res += i;
        }
        return res;
    }
};