class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int matrix[n][n];
        int direction =0;
        int top=0,left=0,right=n-1,bottom=n-1;
        int num=1;
        while(top<=bottom and left<=right){
            if(direction==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=num;
                    num++;
                    }
                direction=1;
                top++;
            }
            else if(direction==1){
                for(int i=top;i<=bottom;i++){matrix[i][right]=num;num++;}
                direction=2;
                right--;
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){matrix[bottom][i]=num;num++;}
                direction=3;
                bottom--;
            }
            else if(direction==3){
                for(int i=bottom;i>=top;i--){matrix[i][left]=num;num++;}
                direction=0;
                left++;
            }
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(matrix[i][j]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
        
    }
};