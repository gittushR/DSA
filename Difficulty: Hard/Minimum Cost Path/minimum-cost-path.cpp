//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        distance[0][0] = grid[0][0];
        q.push({grid[0][0], {0, 0}});
        
        while(!q.empty()){
            int dist = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    if(dist+grid[nrow][ncol] < distance[nrow][ncol]){
                        distance[nrow][ncol] = dist+grid[nrow][ncol];
                        q.push({distance[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        
        return distance[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends