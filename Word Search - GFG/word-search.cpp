//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i, int j,int index,vector<vector<char>>& board, string word){
        int n = board.size(), m = board[0].size();
        if(index==word.size())return true;
        if(i < 0 or j < 0 or i >= n or j >= m) return false;
        bool check = false;
        if(word[index] == board[i][j]){
            char temp = word[index];
            board[i][j] = '#';
            check = dfs(i+1, j, index+1, board, word) or dfs(i-1, j, index+1, board, word) or 
                dfs(i, j+1, index+1, board, word) or dfs(i, j-1, index+1, board, word);
            board[i][j] = temp;
        }
        
        return check;
    }
    bool isWordExist(vector<vector<char>>& grid, string word) {
        // Code here
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends