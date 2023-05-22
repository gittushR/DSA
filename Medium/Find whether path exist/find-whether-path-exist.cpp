//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        pair<int,int> src;
        pair<int,int> dest;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    src.first=i;
                    src.second=j;
                }
                if(grid[i][j]==2){
                    dest.first=i;
                    dest.second=j;
                }
            }
        }
        
        q.push(src);
        vis[src.first][src.second]=1;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and
                !vis[nrow][ncol] and (grid[nrow][ncol]==3 or grid[nrow][ncol]==2)){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    if(nrow==dest.first and ncol==dest.second)return true;
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
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends