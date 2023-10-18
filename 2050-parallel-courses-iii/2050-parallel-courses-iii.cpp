class Solution {
public:
  int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
    vector<int> inDeg(n, 0);
    vector<vector<int>> adj(n);
    for(int i=0; i<r.size(); i++){
      adj[r[i][0]-1].push_back(r[i][1]-1);
      inDeg[r[i][1]-1]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int , int>>> pq;
    for(int i=0; i<n; i++) if(inDeg[i]==0) pq.push({time[i], i});
    int weig=0;
    while(!pq.empty()){
      weig = pq.top().first;
      int node = pq.top().second;
      pq.pop();
      for(auto &it : adj[node])
        if(--inDeg[it]==0) pq.push({weig+time[it], it});
    }
    return weig;
  }
};