class Solution {
public:
    vector<int> getRow(int n) {
        vector< int> ans;
        long long int res=1;
        for(int i=0;i<n;i++){
            ans.push_back(res);
            res*=(n-i);
            res/=(i+1);
            
        }
        ans.push_back(1);
        return ans;
    }
};