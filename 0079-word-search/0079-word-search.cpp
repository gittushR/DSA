class Solution {
public:
    bool dfs(int i, int j,int index,vector<vector<char>>& board, string word){
        int n = board.size(), m = board[0].size();
        if(index==word.size())return true;
        if(i < 0 or j < 0 or i >= n or j >= m) return false;
        
        bool all = false;
        if(word[index] == board[i][j])
        {
            char temp = word[index];
            board[i][j] = '#';
            all = dfs(i+1, j, index+1, board, word) or dfs(i-1, j, index+1, board, word) or 
                dfs(i, j+1, index+1, board, word) or dfs(i, j-1, index+1, board, word);
            
            board[i][j] = temp;
        }
        
        return all;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        int n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                    if(dfs(i,j,0,grid,word))return true;
                }
            }
        }
        return false;
    }
};