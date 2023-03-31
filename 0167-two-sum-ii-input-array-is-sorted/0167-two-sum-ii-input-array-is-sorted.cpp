class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        vector<int> ans;
        int n=arr.size();
        int s=0,e=n-1;
        while(s<e){
            if(arr[s]+arr[e]==k){
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if((arr[s]+arr[e])>k)e--;
            else s++;
        }
        return ans;
    }
};