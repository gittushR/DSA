class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        int srow=0;
        int scol=0;
        if(grid[0][0]==1)return -1;
        q.push({0,{srow,scol}});
        dist[srow][scol]=0;
        
        int drow[]={-1,-1,0,1,1,1,0,-1};
        int dcol[]={0,1,1,1,0,-1,-1,-1};
        
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==n-1 and col==n-1)return distance+1;
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and 
                distance+1<dist[nrow][ncol] and grid[nrow][ncol]==0){
                    dist[nrow][ncol]=distance+1;
                    q.push({distance+1,{nrow,ncol}});
                    
                }
            }
        }
        return -1; 
    }
};