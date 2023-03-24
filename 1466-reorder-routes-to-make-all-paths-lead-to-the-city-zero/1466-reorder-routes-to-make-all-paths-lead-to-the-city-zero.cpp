class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i : connections) {
            adj[i[0]].push_back({i[1], 0});
            adj[i[1]].push_back({i[0], 1});
        }

        int ans = 0;
        queue<int> q;
        vector<int> vis(n);
        vis[0] = 1;
        q.push(0);

        while (q.size()) {
            int node = q.front();
            vis[node] = 1;
            q.pop();

            for (auto i : adj[node]) {
                if (!vis[i.first]) {
                    if (!i.second) ans++;
                    q.push(i.first);
                }
            }
        }

        return ans;
    }
};