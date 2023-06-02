// class DisjointSet {
// public:
//     vector<int> rank, parent, size;
//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// class Solution {
// private:
//     double distance(int x1, int y1, int x2, int y2){
//         long long x=abs(x2-x1);
//         long long y=abs(y2-y1);
//         long long d=x*x+y*y;
//         return pow(d,0.5);
//     }    
// public:
//     int maximumDetonation(vector<vector<int>>& bombs) {
//         DisjointSet ds(bombs.size());
//         map<int,vector<int>> mp;
//         for(int i=0;i<bombs.size();i++){
//             mp[i]=bombs[i];
//         }
//         for(auto it:mp){
//             int bombNum=it.first;
//             int x1=it.second[0];
//             int y1=it.second[1];
//             int radius=it.second[2];
//             for(int i=0;i<bombs.size();i++){
//                 if(bombNum==i)continue;
//                 int x2=bombs[i][0];
//                 int y2=bombs[i][1];
//                 if(distance(x1,y1,x2,y2)<=radius){
//                     if(ds.findUPar(i)!=ds.findUPar(bombNum)) ds.unionBySize(bombNum,i);
//                 }
//             }
//         }
//         int maxi=0;
//         for(int i=0;i<bombs.size();i++){
//             maxi=max(maxi,ds.size[i]);
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    #define ll long long
    void dfs(int src,vector<int>& vis,vector<int> adj[]){
        vis[src]=1;
        for(int x:adj[src]){
            if(vis[x]==0){
                dfs(x,vis,adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            ll r1=bombs[i][2];
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            for(int j=0;j<n;j++){
                if(i!=j){
                    ll x2=bombs[j][0];
                    ll y2=bombs[j][1];
                    ll r2=bombs[j][2];
                    ll dsq=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);;
                    if(dsq<=r1*r1)adj[i].push_back(j); 
                }
            }
        }
        vector<int> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            dfs(i,vis,adj); 
            int cnt=0;
            for(int j=0;j<n;j++) 
              if(vis[j]==1) cnt++;
            ans=max(ans,cnt);
            fill(vis.begin(),vis.end(),0);
        }
        return ans;
    }
};