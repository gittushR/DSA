class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> Map;
        for(int i = 0; i < n; i++) {
            Map[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        vector<int> currLayer;
        currLayer.push_back(0);
        visited[0] = true;
        int ans = -1;
        while(!currLayer.empty()) {
            ans++;
            vector<int> nextLayer;
            for(int currNode: currLayer) {
                if(currNode == n - 1) return ans;
                for(int childNode: Map[arr[currNode]]) {
                    if(!visited[childNode]) {
                        visited[childNode] = true;
                        nextLayer.push_back(childNode);
                    }
                }
                Map[arr[currNode]].clear();
                if(currNode < n - 1 && !visited[currNode + 1]) {
                    visited[currNode + 1] = true;
                    nextLayer.push_back(currNode + 1);
                }
                if(currNode > 0 && !visited[currNode - 1]) {
                    visited[currNode - 1] = true;
                    nextLayer.push_back(currNode - 1);
                }
            }
            currLayer = nextLayer;
        }
        return -1;
    }
};