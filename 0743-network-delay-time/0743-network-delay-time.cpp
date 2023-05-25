class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> time(n+1,1e9);
        time[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;
                if(t+edw<time[adjnode]){
                    time[adjnode]=t+edw;
                    pq.push({time[adjnode],adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(time[i]==1e9)return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};