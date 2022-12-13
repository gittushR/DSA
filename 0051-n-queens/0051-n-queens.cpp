class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int> leftrow(n,0), diagD(2*n-1,0), diagU(2*n-1,0);
        solve(0,ans,board,leftrow,diagD,diagU,n);
        return ans;
    }
    void solve(int col,vector<vector<string>> &ans, vector<string> &board, vector<int> &left,vector<int> &diagD,vector<int> &diagU, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(left[row]==0 && diagD[row+col]==0 && diagU[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                diagD[row+col]=1;
                diagU[n-1+col-row]=1;
                solve(col+1,ans,board,left,diagD,diagU,n);
                board[row][col]='.';
                left[row]=0;
                diagD[row+col]=0;
                diagU[n-1+col-row]=0;
            }
        }
    }
};