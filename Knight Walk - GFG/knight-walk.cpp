//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<vector<int>>vis(N,vector<int>(N,0)); 
	    queue<pair<pair<int,int>,int>>q; 
	    int ki = KnightPos[0]-1;    
	    int kj = KnightPos[1]-1;   
	    int fi = TargetPos[0]-1;    
	    int fj = TargetPos[1]-1;   
	    
	    if(ki==fi && kj==fj){    
	        return 0;
	    }
	    int drow[8] = {-2,-1,+1,+2,+2,+1,-1,-2}; 
        int dcol[8] = {+1,+2,+2,+1,-1,-2,-2,-1};
        
        
	    q.push({{ki,kj},0});
	    vis[ki][kj] = 1;
	    while(q.size()>0){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int dis = q.front().second;
	        q.pop();
	        for(int i=0;i<8;i++){
	            int nrow = row + drow[i];
	            int ncol = col + dcol[i];
	         
	            if(nrow==fi && ncol==fj){
	                return dis+1; 
	            }
	            
	            if(nrow>=0 && nrow<N && ncol>=0 && ncol<N && vis[nrow][ncol]==0){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow,ncol},dis+1});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends