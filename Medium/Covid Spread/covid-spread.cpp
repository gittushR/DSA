//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> grid)
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        int safe=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    safe++;
                }
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int timeTaken=0;
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            timeTaken=max(timeTaken,t);
            
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 and nc>=0 and nr<n and nc<m and
                !vis[nr][nc] and grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({t+1,{nr,nc}});
                    safe--;
                }
            }
        }
        if(safe!=0)return -1;
        return timeTaken;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends