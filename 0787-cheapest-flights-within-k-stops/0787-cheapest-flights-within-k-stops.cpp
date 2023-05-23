class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            
            if(stops>K)continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edW=it.second;
                if(stops<=K and dist[adjnode]>cost+edW){
                    dist[adjnode]=cost+edW;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }
        
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};