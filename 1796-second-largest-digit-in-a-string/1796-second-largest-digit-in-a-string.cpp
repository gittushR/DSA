class Solution {
public:
    int secondHighest(string s) {
        set<int> num;
        vector<int> nums;
        for(auto it : s){
            if(it>= '0' and it<='9')num.insert(it - '0');
        }
        if(num.size()<2)return -1;
        for(auto it: num)nums.push_back(it);
        int n1=nums[0];int n2=nums[1];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>n1){
                n2=n1;
                n1=nums[i];
            }else if(nums[i]<n1 and nums[i]>n2){
                n2=nums[i];
            }
        }
        return n2;
    }
};