//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(), m = grid[0].size(), l = word.size();
	    vector<int> dx = {-1, 0, 1, 0, -1, 1, 1, -1}, dy = {0, 1, 0, -1, -1, 1, -1, 1};
	    set<vector<int>> st;
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            
	            if(word[0] != grid[i][j]) {
	                continue;
	            }
	            
	            for(int k=0; k<8; k++) {
	                int p = 1;
	                int x = i + dx[k], y = j + dy[k];
	                while(p < l && x >= 0 && x < n && y >= 0 && y < m && word[p] == grid[x][y]) {
	                   
	                    x += dx[k];
	                    y += dy[k];
	                    p++;
	                }
	                if(p == l) {
	                    st.insert({i, j});
	                }
	                
	            }
	        }
	    }
	    vector<vector<int>> ans(st.begin(), st.end());
	    return ans;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends