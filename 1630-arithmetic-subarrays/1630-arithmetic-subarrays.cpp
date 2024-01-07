class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            vector<int> vec(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(vec.begin(), vec.end());
            
            if(vec.size() < 2) ans.push_back(true);
            else{
                bool flag = true;
                int diff = vec[1] - vec[0];
                for(int j = 1; j < vec.size(); j++){
                    if(vec[j] - vec[j-1] != diff) flag = false;
                }
                ans.push_back(flag);
            }
        }
        return ans;
    }
};