//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int t){
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            cost[u][v]=wt;
            cost[v][u]=wt;
        }
        for(int i=0;i<n;i++){
            cost[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (cost[i][k] == INT_MAX || cost[k][j] == INT_MAX)
						continue;
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int countMax=n;
        int city=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=t){
                    count++;
                }
            }
            if(count<=countMax){
                countMax=count;
                city=i;
            }
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends