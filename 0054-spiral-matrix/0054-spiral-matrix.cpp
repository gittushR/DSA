class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int dir=0;
        int top=0,bottom=n-1;
        int left=0,right=m-1;
        vector<int> ans;
        while(top<=bottom and left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                dir=1;
            }else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                dir=2;
            }else if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir=3;
            }else{
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                dir=0;
            }
        }
        return ans;
    }
};