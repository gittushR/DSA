class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(auto it:nums){
            if(it<0)neg--;
            else if(it==0){
                return 0;
            }
        }
        if(neg%2==0)return 1;
        else return -1;
    }
};