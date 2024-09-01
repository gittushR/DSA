class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n));
        int num=arr.size();
        if(num<m*n or num>n*m)return {};
        int row=0;
        int index=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=arr[index];
                index++;
            }
        }
        return ans;
    }
};