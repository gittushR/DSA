//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  int findPar(int node, vector<int> &par){
      if(node==par[node])return node;
      return par[node]=findPar(par[node],par);
  }
  void unionbyRank(int u, int v, vector<int> &rank, vector<int> &par){
      int uu=findPar(u,par);
      int uv=findPar(v,par);
      if(rank[uu]<rank[uv]){
          par[uu]=uv;
      }else if(rank[uv]<rank[uu]){
          par[uv]=uu;
      }else{
          par[uv]=uu;
          rank[uu]++;
      }
  }
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        vector<int> par(n);
        for(int i=0;i<n;i++)par[i]=i;
        
        vector<int> rank(n,0);
        
        int extraEdge=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(findPar(u,par)==findPar(v,par)){
                extraEdge++;
                continue;
            }
            else{
                unionbyRank(u,v,rank,par);
            }
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(par[i]==i)components++;
        }
        int ans=components-1;
        if(extraEdge>=ans)return ans;
        return -1;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends